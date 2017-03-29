#ifndef __TREE_H__
#define __TREE_H__

#include <list>

/*
 * Preorder: 	Root -> Left -> Right
 * Inorder: 	Left -> Root -> Right
 * Postorder: Left -> Right -> Root
 * Depth-first: Same as Preorder
 * Breadth-first
 */
struct sNode {
	struct sNode *pParent;
	struct sNode *pLeft, *pRight;
	int iValue;

	sNode() {
		pParent = pLeft = pRight = NULL;
	}
};

class CTree
{
public:
	CTree(int iVal);
	~CTree();

public:
	void AddAsLeft(int iParent, int iVal);
	void AddAsRight(int iParent, int iVal);
	void Show();
	sNode* GetRoot();
	void Preorder(sNode *pNode);
	void Inorder(sNode *pNode);
	void Postorder(sNode *pNode);

	//void DFS(sNode *pNode); // Same as Preorder
	void BFS(sNode *pNode);

private:
	std::list<sNode*> m_lstNode;

private:
	void _NewChild(sNode *pParent, sNode **ppLinkTo, int iVal);
	static void _PrintValue(sNode *pNode);
};

#endif
