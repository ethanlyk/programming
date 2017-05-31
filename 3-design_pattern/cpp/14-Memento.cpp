#include <stdio.h>
#include <time.h>

#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

/*
 * Memento
 */
class Backup {
public:
	Backup(string str) {
		m_strState = str;
		time(&m_time);
	}

	time_t GetTime() {
		return m_time;
	}

	string GetState() {
		return m_strState;
	}

private:
	string m_strState;
	time_t m_time;
};

/*
 * CareTaker
 */
class Recovery {
public:
	~Recovery() {
		for (int  i = 0; i < m_ayBackup.size(); i++) {
			if (m_ayBackup[i]) {
				delete m_ayBackup[i];
			}
		}
		m_ayBackup.clear();
	}

	void Add(Backup *pBackup) {
		m_ayBackup.push_back(pBackup);
	}

	Backup* Retrieve(time_t time) {
		int i = 0;
		for (vector<Backup*>::iterator it = m_ayBackup.begin(); it != m_ayBackup.end(); it++) {
			if ((*it)->GetTime() == time) {
				m_ayBackup.erase(it);
				return (*it);
			}
		}

		//return NULL;
		throw invalid_argument("Not found");
	}

private:
	vector<Backup*> m_ayBackup;
};

/*
 * Originator
 */
class Application {
public:
	Application() {
		m_strState = "default setting";
	}

	Backup* DoBackup() {
		return new Backup(m_strState);
	}

	void Recover(Backup *pBackup) {
		m_strState = pBackup->GetState();
	}

	void SetState(string str) {
		m_strState = str;
	}

	string GetState() {
		return m_strState;
	}

private:
	string m_strState;
};


int main() {
	Application application;
	Recovery recovery;

	printf("Origin: %s\n", application.GetState().c_str());

	Backup *pBackup = application.DoBackup();
	recovery.Add(pBackup);

	application.SetState("mysetting");
	printf("New: %s\n", application.GetState().c_str());

	time_t time = pBackup->GetTime();
	Backup *pRecovery = recovery.Retrieve(time);
	application.Recover(pRecovery);
	printf("Recover: %s\n", application.GetState().c_str());
	
	delete pRecovery;
}
