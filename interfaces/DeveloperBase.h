#ifndef DEVELOPER_BASE
#define DEVELOPER_BASE

class DeveloperBase{
	public:
		DeveloperBase(){

		}
		virtual ~DeveloperBase(){

		}

		virtual bool invoke(bool) = 0;
};

#endif

