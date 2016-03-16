.PHONY: clean All

All:
	@echo "----------Building project:[ VectorList - Debug ]----------"
	@cd "VectorList" && "$(MAKE)" -f  "VectorList.mk"
clean:
	@echo "----------Cleaning project:[ VectorList - Debug ]----------"
	@cd "VectorList" && "$(MAKE)" -f  "VectorList.mk" clean
