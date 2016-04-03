# VectorList

VectorList is a rough attempt at CGAL's Compact_Container class.
I'm not sure how they chose to implement thread-safety but we use
an iterator which contains a pointer to the appropriate lock for
the element in the container. 

What this means is, all reads and writes done with an iterator are
"sane". There will not be any simultaneous reads and writes of a 
an element in the container.

## Iterability

The iterator is bi-directional and allows for blocking operations
to be performed on the stored element.

The interface is fairly standard, for example:
```cpp
for (auto it = vl.begin(); it != vl.end(); ++it) {
  /* ... */
}
```

Because the iterator is already bi-directional in nature, 
there didn't seem to be any need to create a reverse iterator.
Instead, reverse iteration would be done in the iterator's
natural way, we just change the start and end points.
```cpp
for (auto it = vl.rbegin(); it != vl.rend(); --it) {
  /* ... */
}
```
