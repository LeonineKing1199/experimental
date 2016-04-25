#ifndef REGULUS_UNROLLED_LIST_HPP_
#define REGULUS_UNROLLED_LIST_HPP_

#include <type_traits>
#include <memory>
#include <iterator>
#include <cassert>
#include <iostream>

namespace regulus
{
  template <typename T>
  class unrolled_list
  {
  public:
    typedef T value_type;
    typedef std::size_t size_type;
    typedef std::size_t difference_type;
    typedef value_type* pointer;
    typedef value_type& reference;
    typedef value_type const* const_pointer;
    typedef value_type const& const_reference;
    
  private:
    size_type const static array_size_ = 32;
  
    class node
    {
    public:
      node* next;
      node* prev;
      size_type size;
      
    private:
      std::aligned_storage_t<sizeof(T), alignof(T)> data_[array_size_];
      
    public:
      node(void)
        : next{nullptr}
        , prev{nullptr}
        , size{0}
      {}
      
      ~node(void)
      {
        for (size_type i = 0; i < size; ++i) {
          reinterpret_cast<const_pointer>(data_ + i)->~value_type();
        }
      }
      
      reference get(size_type const idx)
      {
        return *reinterpret_cast<pointer>(data_ + idx);
      }
      
      template <typename ...Args>
      void set_at(size_type idx, Args&&... args)
      {
        new(reinterpret_cast<pointer>(data_ + idx)) value_type{std::forward<Args>(args)...};
      }
      
      pointer data(void)
      {
        return reinterpret_cast<pointer>(data_);
      }
    };
    
    class iterator
    {      
    public:
      typedef std::bidirectional_iterator_tag iterator_category;
      
    private:
      friend class unrolled_list;
      
      node* curr_node_;
      difference_type idx_;
      
    public:
      iterator(void)
        : curr_node_{nullptr}
        , idx_{0}
      {}
    
      iterator(node* curr_node, difference_type const idx)
        : curr_node_{curr_node}
        , idx_{idx}
      {}
      
      iterator(iterator const& other)
        : curr_node_{other.curr_node_}
        , idx_{other.idx_}
      {}
        
      ~iterator(void) = default;
        
      iterator& operator=(iterator const& other)
      {
        curr_node_ = other.curr_node_;
        idx_ = other.idx_;
        return *this;
      }
      
      bool operator==(const iterator& other)
      {
        return (curr_node_ == other.curr_node_ && idx_ == other.idx_);
      }
      
      bool operator!=(const iterator& other)
      {
        return !(*this == other);
      }      
      
      reference operator*(void)
      {
        return curr_node_->get(idx_);
      }
      
      pointer operator->(void)
      {
        // this function seemed super confusing to me at first
        // dereference of this gives us an iterator
        // dereference of an iterator gives a reference
        // return the address of the reference
        return std::addressof(*(*this));
      }
      
      iterator& operator++(void)
      {
        ++idx_;
        if (idx_ >= array_size_) {
          curr_node_ = curr_node_->next;
          idx_ = 0;
        }
        
        std::cout << "\nNow at : " << curr_node_;
        return *this;
      }
      
      iterator operator++(int)
      {
        auto tmp = *this;
        ++(*this);
        return tmp;
      }
      
      iterator& operator--(void)
      {
        --idx_;
        
        if (idx_ < 0) {
          curr_node_ = curr_node_->prev;
          idx_ = (curr_node_ == nullptr ? -1 : curr_node_->size);
        }
        
        return *this;
      }
      
      iterator operator--(int)
      {
        auto tmp = *this;
        --(*this);
        return tmp;
      }
    };
    
  private:
    node* head_;
    node* tail_;
    
    size_type size_;
    size_type capacity_;
    
    
  private:
    node* insert_node_after(node* curr_node)
    {
      std::cout << "\nInserting new node after...";
      auto new_node = new node;
      auto old_curr_node_next = curr_node->next; // maybe null
      
      curr_node->next = new_node;
      new_node->prev = curr_node;
      new_node->next = old_curr_node_next;
      
      if (new_node->next == nullptr) {
        std::cout << "\nRe-adjusting the tail_ pointer...";
        tail_ = new_node;
      }
      
      capacity_ += array_size_;
      
      assert(curr_node->next == new_node);
      assert(new_node->prev == curr_node);
      
      return new_node;
    }
    
  public:
    unrolled_list(void)
      : head_{new node}
      , tail_{head_}
      , size_{0}
      , capacity_{0}
    {}
    
    ~unrolled_list(void)
    {
      tail_ = nullptr;
      while (head_ != nullptr) {
        auto tmp = head_;
        head_ = head_->next;
        tmp->~node();
        delete tmp;
      }
    }
    
    size_type size(void) const
    {
      return size_;
    }
    
    iterator begin(void) const
    {
      return iterator{head_, 0};
    }
    
    iterator end(void) const
    {
      std::cout << "\ntail_ pointer : " << tail_;
      return iterator{tail_, tail_->size};
    }
        
    template <typename ...Args, 
              typename = std::enable_if_t<std::is_move_assignable<T>::value>>
    iterator emplace(iterator where, Args&&... args)
    {
      node* curr_node = where.curr_node_;
      node* dest = curr_node;
      size_type curr_idx = where.idx_;
    
      assert(curr_node != nullptr);
      assert(curr_node == head_);
    
      if (curr_node->size == 0) {
        curr_node->set_at(0, std::forward<Args>(args)...);
        ++curr_node->size;
        ++size_;
        
        assert(curr_node->size == 1);
        
        return iterator{curr_node, 0};
      }
    
      // is the node full?
      if (curr_node->size == array_size_) {
        // we then construct a new node after the current one
        node* new_node = insert_node_after(curr_node);
        
        assert(curr_node->next == new_node);
        assert(new_node->prev == curr_node);
        
        // now we must move half the elements over!
        size_type const num_to_move = array_size_ / 2;
        pointer input = curr_node->data() + num_to_move;
        pointer output = new_node->data();
        
        for (size_type i = 0; i < num_to_move; ++i, ++input, ++output) {
          *output = std::move(*input);
        }
        
        // we then remember to adjust the size...
        curr_node->size = num_to_move;
        new_node->size = num_to_move;
        
        // now, which node do we insert into?
        dest = (curr_idx > num_to_move ? new_node : curr_node);
        curr_idx %= num_to_move;
        
        // more efficient to just write to the end
        // of the node before the new one
        if (curr_idx == 0 && dest == new_node) {
          curr_idx = num_to_move;
          dest = curr_node;
        }
      }
      
      assert(dest->size >= 1 && dest->size <= array_size_);
      
      for (size_type i = dest->size; i > curr_idx && i > 0; --i) {
        dest->set_at(i, std::move(dest->get(i - 1)));
      }

      dest->set_at(curr_idx, std::forward<Args>(args)...);
      ++dest->size;
      ++size_;
      
      return iterator{dest, curr_idx};
    }
  };
}

#endif // REGULUS_UNROLLED_LIST_HPP_
