#include <stdio.h>
#include <algorithm>
#include <queue>

#include "tree.h"

CTree::CTree(int iVal)
{
	sNode *p = new sNode();
	p->iValue = iVal;

	m_lstNode.push_back(p);
}

CTree::~CTree()
{
	for (std::list<sNode*>::iterator it = m_lstNode.begin(); it != m_lstNode.end(); it++) {
		delete (*it);
	}
	m_lstNode.clear();
}

void CTree::_NewChild(sNode *pParent, sNode **ppLinkTo, int iVal)
{
	sNode *p = new sNode();
	p->iValue = iVal;

	(*ppLinkTo) = p;
	p->pParent = pParent;

	m_lstNode.push_back(p);
}

void CTree::AddAsLeft(int iParent, int iVal)
{
	for (std::list<sNode*>::iterator it = m_lstNode.begin(); it != m_lstNode.end(); it++) {
		if ((*it)->iValue == iParent) {
			_NewChild(*it, &((*it)->pLeft), iVal);

			break;
		}
	}
}

void CTree::AddAsRight(int iParent, int iVal)
{
	for (std::list<sNode*>::iterator it = m_lstNode.begin(); it != m_lstNode.end(); it++) {
		if ((*it)->iValue == iParent) {
			_NewChild(*it, &((*it)->pRight), iVal);

			break;
		}
	}
}

void CTree::_PrintValue(sNode *pNode)
{
	if (pNode != NULL) {
		printf(" %d", pNode->iValue);
	}
}

void CTree::Show()
{
	printf("Show()\n");
	for_each(m_lstNode.begin(), m_lstNode.end(), _PrintValue);
	/*
	for (std::list<sNode*>::iterator it = m_lstNode.begin(); it != m_lstNode.end(); it++) {
		printf(" %d", (*it)->iValue);
	}
	*/
	printf("\n\n");
}

sNode* CTree::GetRoot()
{
	return m_lstNode.front();
}

void CTree::Preorder(sNode *pNode)
{
	if (pNode != NULL) {
		_PrintValue(pNode);
		Preorder(pNode->pLeft);
		Preorder(pNode->pRight);
	}
}

void CTree::Inorder(sNode *pNode)
{
	if (pNode != NULL) {
		Inorder(pNode->pLeft);
		_PrintValue(pNode);
		Inorder(pNode->pRight);
	}
}

void CTree::Postorder(sNode *pNode)
{
	if (pNode != NULL) {
		Postorder(pNode->pLeft);
		Postorder(pNode->pRight);
		_PrintValue(pNode);
	}
}

void CTree::BFS(sNode *pNode)
{
	if (pNode != NULL) {
		std::queue<sNode *> qCandidate;
		qCandidate.push(pNode);
		while (!qCandidate.empty()) {
			sNode *pItem = qCandidate.front();
			_PrintValue(pItem);
			
			if (pItem->pLeft != NULL) {
				qCandidate.push(pItem->pLeft);
			}

			if (pItem->pRight != NULL) {
				qCandidate.push(pItem->pRight);
			}

			qCandidate.pop();
		}
	}
}

