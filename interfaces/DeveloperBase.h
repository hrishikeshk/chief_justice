#ifndef DEVELOPER_BASE
#define DEVELOPER_BASE

class DeveloperBase{
	public:
		DeveloperBase(){

		}
		virtual ~DeveloperBase(){

		}
#ifdef _DEBUG_BUILD_
		virtual bool invoke(bool) = 0;
#endif

};

#endif

