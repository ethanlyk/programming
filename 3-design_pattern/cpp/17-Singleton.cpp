#include <stdio.h>

class Singleton {
public:
	static Singleton* Instance() {
		if (m_pInstance == NULL) {
			m_pInstance = new Singleton();
		}

		return m_pInstance;
	}

	void Release() {
		if (m_pInstance) {
			delete m_pInstance;
		}
	}

	void Do() {
		printf("Do something\n");
	}

private:
	static Singleton* m_pInstance;

	Singleton() {};
};

Singleton* Singleton::m_pInstance = NULL;

int main() {
	Singleton *pInstance = Singleton::Instance();
	pInstance->Do();

	pInstance->Release();
}
