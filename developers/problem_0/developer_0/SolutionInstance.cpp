#ifndef SOLUTIONINSTANCE
#define SOLUTIONINSTANCE

#include "Solution.h"
#include "interfaces/DeveloperBase.h"
#include "testers/problem_0/src/cpp/DeveloperImpl.h"

extern "C"
{
	DeveloperBase* create(){
		Solution* p_soln = new Solution();
		return new DeveloperImpl<Solution>(p_soln);
	}

	void destroy(DeveloperBase* p){
		delete p;
	}
}

#endif

