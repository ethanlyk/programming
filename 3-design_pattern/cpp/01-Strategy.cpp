#include <stdio.h>

class IStrategy {
public:
	virtual void Do() = 0;
};

class StrategyA : public IStrategy {
	void Do() {
		printf("StrategyA::Do()\n");
	}
};

class StrategyB : public IStrategy {
	void Do() {
		printf("StrategyB::Do()\n");
	}
};

int main(int argc, char *argv[]) {
	IStrategy *pObj;

	if (argc > 1) {
		pObj = new StrategyA();
	} else {
		pObj = new StrategyB();
	}

	pObj->Do();

	delete pObj;
}
