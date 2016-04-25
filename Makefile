.PHONY: clean All

All:
	@echo "----------Building project:[ UnrolledList - Debug ]----------"
	@cd "UnrolledList" && "$(MAKE)" -f  "UnrolledList.mk"
clean:
	@echo "----------Cleaning project:[ UnrolledList - Debug ]----------"
	@cd "UnrolledList" && "$(MAKE)" -f  "UnrolledList.mk" clean
