#include <stdio.h>
#include <string>
#include <map>

using namespace std;

/*
 * Receiver
 */
class Effect {
public:
	void DoEffect1() {
		printf("\tDo effect1\n");
	}

	void DoEffect2() {
		printf("\tDo effect2\n");
	}

	void DoEffect3() {
		printf("\tDo effect3\n");
	}
};

/*
 * Command
 */
class Command {
public:
	virtual void Execute() = 0;

protected:
	Effect *m_pEffect;
};

class AEffectCommand : public Command {
public:
	AEffectCommand(Effect *ptr) {
		m_pEffect = ptr;
	}

	void Execute() {
		printf("Do AEffect\n");
		m_pEffect->DoEffect1();
		m_pEffect->DoEffect2();
	}
};

class BEffectCommand : public Command {
public:
	BEffectCommand(Effect *ptr) {
		m_pEffect = ptr;
	}

	void Execute() {
		printf("Do BEffect\n");
		m_pEffect->DoEffect2();
		m_pEffect->DoEffect3();
	}
};

/*
 * Invoker
 */
class ImageService {
public:
	~ImageService() {
		for (map<string, Command*>::iterator it = m_map.begin(); it != m_map.end(); it++) {
			if (it->second != NULL) {
				delete it->second;
			}
		}
		m_map.clear();
	}

	void AddCommand(string str, Command *pCmd) {
		m_map[str] = pCmd;
	}

	void Do(string str) {
		map<string, Command*>::iterator it = m_map.find(str);
		if (it != m_map.end()) {
			it->second->Execute();
		} else {
			printf("No such effect: %s\n", str.c_str());
		}
	}

private:
	map<string, Command*> m_map;
};

int main() {
	Effect effect;

	ImageService service;
	service.AddCommand("AEffect", new AEffectCommand(&effect));
	service.AddCommand("BEffect", new BEffectCommand(&effect));

	service.Do("AEffect");
	service.Do("BEffect");
	service.Do("CEffect");
}
