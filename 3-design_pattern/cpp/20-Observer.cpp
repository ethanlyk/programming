#include <stdio.h>

#include <list>

using namespace std;

/*
 * Observer
 */
class IAlarm {
public:
	virtual void Update() = 0;
	virtual ~IAlarm() {};
};

class Light : public IAlarm {
public:
	void Update() {
		printf("Light::Alarm()\n");
	}
};

class Gate : public IAlarm {
public:
	void Update() {
		printf("Gate::Alarm()\n");
	}
};

/*
 * Subject
 */
class SensorSystem {
public:
	void Attach(IAlarm* pObj) {
		m_lstSensor.push_back(pObj);
	}

	void Notify() {
		for (list<IAlarm*>::iterator it = m_lstSensor.begin(); it != m_lstSensor.end(); it++) {
			(*it)->Update();
		}
	}

	void Release() {
		for (list<IAlarm*>::iterator it = m_lstSensor.begin(); it != m_lstSensor.end(); it++) {
			delete (*it);
		}
		m_lstSensor.clear();
	}

private:
	list<IAlarm*> m_lstSensor;
};

int main() {
	SensorSystem system;

	system.Attach(new Light());
	system.Attach(new Gate());

	system.Notify();

	system.Release();
}
