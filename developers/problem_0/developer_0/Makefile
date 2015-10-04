include $(SRC_DIR)/OptMake

SolutionInstance.o:
	$(CC) $(OPTIONS) $(WARN) $(DEBUG) $(DEV_INCLUDES) $(FPIC_OBJ) -o SolutionInstance.o -c SolutionInstance.cpp

libSolution.so: SolutionInstance.o
	$(CC) $(WARN) $(DEBUG) $(SHAREDLIB_FLAGS) -o libSolution.so SolutionInstance.o ../../../testers/problem_0/src/cpp/DeveloperImpl.o

clean:
	rm -rf *.so; rm -rf *.o

