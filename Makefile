.PHONY: clean All

All:
	@echo "----------Building project:[ DS_PECL1 - Debug ]----------"
	@cd "DS_PECL1" && "$(MAKE)" -f  "DS_PECL1.mk"
clean:
	@echo "----------Cleaning project:[ DS_PECL1 - Debug ]----------"
	@cd "DS_PECL1" && "$(MAKE)" -f  "DS_PECL1.mk" clean
