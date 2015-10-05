.PHONY: clean

include $(SRC_DIR)/OptMake

DL_Loader.o: DL_Loader.cpp DL_Loader.h
	$(CC) $(OPTIONS) $(WARN) $(DEBUG) $(INCLUDES) $(FPIC_OBJ) -o DL_Loader.o -c DL_Loader.cpp

Framework.o: Framework.cpp Framework.h
	$(CC) $(OPTIONS) $(WARN) $(DEBUG) $(INCLUDES) $(FPIC_OBJ) -o Framework.o -c Framework.cpp

framework: DL_Loader.o Framework.o
	$(CC) $(WARN) $(DEBUG) $(SHAREDLIB_FLAGS) -ldl -o $(SRC_DIR)/libs/libframework.so DL_Loader.o Framework.o

chief_justice: framework main.cpp
	$(CC) $(OPTIONS) $(WARN) $(DEBUG) -L $(SRC_DIR)/libs -lframework -o $(SRC_DIR)/libs/app main.cpp

clean:
	rm -rf *.o *.so *.a

