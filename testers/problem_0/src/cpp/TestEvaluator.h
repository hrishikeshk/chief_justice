#ifndef TESTEVALUATOR
#define TESTEVALUATOR

#include "interfaces/TestEvaluatorBase.h"

template <typename Solution>
class TestEvaluator : public TestEvaluatorBase{

	Solution*& mp_soln;
	public:
		TestEvaluator(Solution*& p_soln):mp_soln(p_soln){

		}
		~TestEvaluator(){
		}

		TestResult invoke(){

		}
};

#endif

