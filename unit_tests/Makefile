include $(SRC_DIR)/OptMake

.PHONY: unit_tests clean

TST_INCLUDES=-I $(SRC_DIR)/src/cpp -I $(SRC_DIR)/unit_tests

simpledl.o: simpledl.cpp
	$(CC) $(OPTIONS) $(WARN) $(DEBUG) $(INCLUDES) $(FPIC_OBJ) -o simpledl.o -c simpledl.cpp

simpledl.so: simpledl.o
	$(CC) $(WARN) $(DEBUG) $(SHAREDLIB_FLAGS) -o $(SRC_DIR)/libs/libsimpledl.so simpledl.o

simple_tests.o: simple_tests.cpp Test_Utils.h
	$(CC) $(OPTIONS)  $(WARN) $(DEBUG) $(FPIC_OBJ) $(INCLUDES) $(RB_INCLUDES) $(TST_INCLUDES) -o simple_tests.o -c simple_tests.cpp

unit_tests: simple_tests.o simpledl.so
	$(CC) $(OPTIONS) $(WARN) $(DEBUG) -L $(SRC_DIR)/libs -lframework -o $(SRC_DIR)/libs/simple_tests simple_tests.o

clean:
	rm -rf *.o; rm -rf $(SRC_DIR)/libs/simple_tests

