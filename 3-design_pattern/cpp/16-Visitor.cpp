#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <list>

#include "16-Visitor.h"

using namespace std;

/*
 * ObjectStructures
 */
class FriendsGenerator {
public:
	static IFriend* NewFlower(int iRand) {
		switch (iRand) {
			case 0:
				return new FriendsInHighSchool();

			case 1:
				return new FriendsFromNeighbor();

			case 3:
			default:
				return new NewFriends();
		}
	}
};


// Element implementation
void FriendsInHighSchool::Accept(IVisitor *pVisitor) {
	pVisitor->Visit(this);
}

void FriendsFromNeighbor::Accept(IVisitor *pVisitor) {
	pVisitor->Visit(this);
}

void NewFriends::Accept(IVisitor *pVisitor) {
	pVisitor->Visit(this);
}

// Visitor implementation
void Party::Visit(FriendsInHighSchool *pFriends) {
	printf("FriendsInHighSchool\n");
}

void Party::Visit(FriendsFromNeighbor *pFriends) {
	printf("FriendsFromNeighbor\n");
}

void Party::Visit(NewFriends *pFriends) {
	printf("NewFriends\n");
}

void Drink::Visit(FriendsInHighSchool *pFriends) {
	printf("Drink and FriendsInHighSchool\n");
}

void Drink::Visit(FriendsFromNeighbor *pFriends) {
	printf("Drink and FriendsFromNeighbor\n");
}

void Drink::Visit(NewFriends *pFriends) {
	printf("Drink and NewFriends\n");
}


int main() {
	srand(time(NULL));

	list<IFriend *> lstFriend;
	for (int i = 0; i < 10; i++) {
		lstFriend.push_back(FriendsGenerator::NewFlower(rand()%3));
	}

	Party party;
	for (list<IFriend*>::iterator it = lstFriend.begin(); it != lstFriend.end(); it++) {
		(*it)->Accept(&party);
	}

	printf("\n");

	Drink drink;
	for (list<IFriend*>::iterator it = lstFriend.begin(); it != lstFriend.end(); it++) {
		(*it)->Accept(&drink);
	}

	for (list<IFriend*>::iterator it = lstFriend.begin(); it != lstFriend.end(); it++) {
		delete (*it);
	}
	lstFriend.clear();
}
