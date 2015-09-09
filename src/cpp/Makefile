.PHONY: clean

include $(SRC_DIR)/OptMake

DL_Loader.o: DL_Loader.cpp DL_Loader.h
	$(CC) $(OPTIONS) $(WARN) $(DEBUG) $(INCLUDES) $(RB_INCLUDES) $(FPIC_OBJ) -o DL_Loader.o -c DL_Loader.cpp

clean:
	rm -rf *.o *.so *.a

