#include <stdio.h>

class Adaptee {
public:
	void DoAdaptee() {
		printf("DoAdaptee()\n");
	}
};

class IAdapter {
	virtual void Request() = 0;
};

// Use Adaptee as delegation
class Adapter : public IAdapter {
public:
	void Request() {
		m_adaptee.DoAdaptee();
	}

private:
	Adaptee m_adaptee;
};
	
int main() {
	Adapter adapter;
	adapter.Request();
}
