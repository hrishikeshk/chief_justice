#include "TestEnvironment.h"

TestEnvironment::TestEnvironment(TimeLimit_msec tl, MemoryLimit_kbs ml):m_tl(tl), m_ml(ml){
}

TimeLimit_msec TestEnvironment::getTimeLimit(){
	return m_tl;
}

MemoryLimit_kbs TestEnvironment::getMemoryLimit(){
	return m_ml;
}

