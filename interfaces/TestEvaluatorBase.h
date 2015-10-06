#ifndef TESTEVALUATORBASE
#define TESTEVALUATORBASE

enum TestResult {SUCCESS, WRONG_ANSWER, TIME_LIMIT_EXCEEDED, ABNORMAL_END };

class TestEvaluatorBase{
	public:
	virtual ~TestEvaluatorBase(){
	}

	virtual TestResult invoke() = 0;

};

#endif

