#ifndef __VISITOR_H__
#define __VISITOR_H__

class IVisitor;

/*
 * Element
 */
class IFriend {
public:
	virtual void Accept(IVisitor *pVisitor) = 0;
};

class FriendsInHighSchool : public IFriend {
public:
	void Accept(IVisitor *pVisitor);
};

class FriendsFromNeighbor : public IFriend {
public:
	void Accept(IVisitor *pVisitor);
};

class NewFriends : public IFriend {
public:
	void Accept(IVisitor *pVisitor);
};

/*
 * Visitor
 */
class IVisitor {
public:
	virtual void Visit(FriendsInHighSchool *pFriends) = 0;
	virtual void Visit(FriendsFromNeighbor *pFriends) = 0;
	virtual void Visit(NewFriends *pFriends) = 0;
};

class Party : public IVisitor {
public:
	void Visit(FriendsInHighSchool *pFriends);
	void Visit(FriendsFromNeighbor *pFriends);
	void Visit(NewFriends *pFriends);
};

class Drink : public IVisitor {
public:
	void Visit(FriendsInHighSchool *pFriends);
	void Visit(FriendsFromNeighbor *pFriends);
	void Visit(NewFriends *pFriends);
};

#endif
