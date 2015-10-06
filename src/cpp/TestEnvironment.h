#ifndef TESTENVIRONMENT
#define TESTENVIRONMENT

typedef unsigned int TimeLimit_msec;
typedef unsigned int MemoryLimit_kbs;
class TestEnvironment{

	TimeLimit_msec m_tl;
	MemoryLimit_kbs m_ml;
	public:
	TestEnvironment(TimeLimit_msec tl, MemoryLimit_kbs ml);

	TimeLimit_msec getTimeLimit();

	MemoryLimit_kbs getMemoryLimit();
};

#endif

