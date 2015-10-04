.PHONY: clean

include $(SRC_DIR)/OptMake

DeveloperImpl.o:
	$(CC) $(OPTIONS) $(WARN) $(DEBUG) $(DEV_INCLUDES) $(FPIC_OBJ) -o DeveloperImpl.o -c DeveloperImpl.cpp

clean:
	rm -rf *.o *.so *.a

