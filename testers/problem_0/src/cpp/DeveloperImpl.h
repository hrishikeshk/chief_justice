#ifndef DEVELOPERIMPL
#define DEVELOPERIMPL

#include "interfaces/DeveloperBase.h"

template <typename Solution>
class DeveloperImpl : public DeveloperBase{

	Solution* mp_soln;
	public:
		DeveloperImpl(Solution* p_soln):mp_soln(p_soln){

		}
		~DeveloperImpl(){
			delete mp_soln;
		}
		bool invoke(bool b){
			return mp_soln->unit_test_func(b);
		}
};

#endif

