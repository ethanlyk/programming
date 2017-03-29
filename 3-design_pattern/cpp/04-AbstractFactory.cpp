#include <stdio.h>

/********** Product **********/
class IBall {
public:
	virtual void Action() = 0;
};

class Basketball : public IBall {
public:
	void Action() {
		printf("Hand pass\n");
	}
};

class Football : public IBall {
public:
	void Action() {
		printf("Foot pass\n");
	}
};

class IPlayer {
public:
	virtual void Kick(IBall* ball) = 0;
};

class PlayerA : public IPlayer {
public:
	void Kick(IBall* ball) {
		printf("PlayerA\n");
		ball->Action();
	}
};

class PlayerB : public IPlayer {
public:
	void Kick(IBall* ball) {
		printf("PlayerB\n");
		ball->Action();
	}
};

/********** Factory **********/
class IGameFactory {
public:
	virtual IPlayer* MakePlayer() = 0;
	virtual IBall* MakeBall() = 0;
};

class BasketballFactory : public IGameFactory {
public:
	IPlayer* MakePlayer() {
		return new PlayerA();
	}

	IBall* MakeBall() {
		return new Basketball();
	}
};

class FootballFactory : public IGameFactory {
public:
	IPlayer* MakePlayer() {
		return new PlayerB();
	}

	IBall* MakeBall() {
		return new Football();
	}
};
/******************************/
class Match {
public:
	Match(IGameFactory* pFactory) {
		m_player = pFactory->MakePlayer();
		m_ball = pFactory->MakeBall();
	}

	~Match() {
		delete m_player;
		delete m_ball;
	}

	void Play() {
		if (m_player && m_ball) {
			m_player->Kick(m_ball);
		}
	}

private:
	IPlayer* m_player = NULL;
	IBall* m_ball = NULL;
};

int main() {
	Match *pMatch;
	IGameFactory *pFactory;

	printf("Play basketball\n");
	pFactory = new BasketballFactory();
	pMatch = new Match(pFactory);
	pMatch->Play();
	delete pFactory;
	delete pMatch;

	printf("\nPlay football\n");
	pFactory = new FootballFactory();
	pMatch = new Match(pFactory);
	pMatch->Play();
	delete pFactory;
	delete pMatch;

}
