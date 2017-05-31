#ifndef __MEDIATOR_H__
#define __MEDIATOR_H__

#include <string>

using namespace std;

class Exit;
class Browse;
class Welcome;
class Mediator;

class Exit {
public:
	Exit(Mediator *pObj);
	void Execute();

private:
	Mediator* m_pMediator;
};

class Browse {
public:
	Browse(Mediator *pObj);
	void Execute();

private:
	Mediator* m_pMediator;
};

class Welcome {
public:
	Welcome(Mediator *pObj);
	void Execute();

private:
	Mediator* m_pMediator;
};

class Purchase {
public:
	Purchase(Mediator *pObj);
	void Execute(); 

private:
	Mediator* m_pMediator;
};

class Mediator {
public:
	Mediator();
	~Mediator();
	void Handle(string strState);
	Welcome* GetWelcome();

private:
	Welcome *m_pWelcome;
	Browse *m_pBrowse;
	Purchase *m_pPurchase;
	Exit *m_pExit;
};

#endif
