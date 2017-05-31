#include <stdio.h>

/* 
 * The forward declaration is an "incomplete type", 
 * the only thing you can do with such a type is instantiate a pointer to it, 
 * or reference it in a function declaration
 */
#include "09-Mediator.h"

// class Exit
Exit::Exit(Mediator *pObj) {
	m_pMediator = pObj;
}

void Exit::Execute() {
	printf("exit\n");
}

// class Browse
Browse::Browse(Mediator *pObj) {
	m_pMediator = pObj;
}

void Browse::Execute() {
	printf("shop.purchase\n");
	m_pMediator->Handle("shop.purchase");
}

// class Welcome
Welcome::Welcome(Mediator *pObj) {
	m_pMediator = pObj;
}

void Welcome::Execute() {
	printf("welcome.shop\n");
	m_pMediator->Handle("welcome.shop");
}

// Purchase
Purchase::Purchase(Mediator *pObj) {
	m_pMediator = pObj;
}

void Purchase::Execute() {
	printf("Thanks for your purchase\n");
	m_pMediator->Handle("purchase.exit");
}

// Mediator
Mediator::Mediator() {
	m_pWelcome = new Welcome(this);
	m_pBrowse = new Browse(this);
	m_pPurchase = new Purchase(this);
	m_pExit = new Exit(this);
}

Mediator::~Mediator() {
	if (m_pWelcome) {
		delete m_pWelcome;
	}

	if (m_pBrowse) {
		delete m_pBrowse;
	}

	if (m_pPurchase) {
		delete m_pPurchase;
	}

	if (m_pExit) {
		delete m_pExit;
	}
}

void Mediator::Handle(string strState) {
	if (strState == "welcome.shop") {
		m_pBrowse->Execute();
	} else if (strState == "shop.purchase") {
		m_pPurchase->Execute();
	} else if (strState == "welcome.exit") {
		m_pExit->Execute();
	} else if (strState == "shop.exit") {
		m_pExit->Execute();
	} else if (strState == "purchase.exit") {
		m_pExit->Execute();
	}
}

Welcome* Mediator::GetWelcome() {
	return m_pWelcome;
}

//
int main() {
	Mediator *pMediator = new Mediator();
	pMediator->GetWelcome()->Execute();
}
