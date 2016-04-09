.PHONY: clean All

All:
	@echo "----------Building project:[ UnrolledList - debug ]----------"
	@cd "UnrolledList" && "$(MAKE)" -f  "UnrolledList.mk"
clean:
	@echo "----------Cleaning project:[ UnrolledList - debug ]----------"
	@cd "UnrolledList" && "$(MAKE)" -f  "UnrolledList.mk" clean
