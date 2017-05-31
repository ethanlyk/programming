#include <stdio.h>

#include <string>

using namespace std;

/*
 * State
 */
class IAnimal {
public:
	virtual string Talk() = 0;
};

class Frog : public IAnimal {
public:
	string Talk() {
		return "ggg!";
	}
};

class Cat : public IAnimal {
public:
	string Talk() {
		return "miao";
	}
};

/*
 * Context
 */
class Creature {
public:
	Creature() {
		m_pState = new Frog();
	}

	~Creature() {
		if (m_pState) {
			delete m_pState;
		}
	}

	void Greet() {
		printf("%s\n", m_pState->Talk().c_str());
	}

	void ToCat() {
		if (m_pState) {
			delete m_pState;
		}

		m_pState = new Cat();
	}

private:
	IAnimal *m_pState;
};


int main() {
	Creature creature;
	creature.Greet();

	creature.ToCat();
	creature.Greet();
}
