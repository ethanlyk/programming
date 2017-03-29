#include <stdio.h>

#include "tree.h"

int main()
{
	CTree *pTree = new CTree(0);

	// Construct tree
	pTree->AddAsLeft(0, 1);
	pTree->AddAsRight(0, 2);

	pTree->AddAsLeft(1, 3);
	pTree->AddAsRight(1, 4);

	pTree->AddAsRight(2, 5);
	
	pTree->AddAsLeft(3, 6);
	pTree->AddAsRight(3, 7);

	pTree->AddAsLeft(5, 8);
	pTree->AddAsRight(5, 9);

	pTree->Show();

	printf("Preorder:\n");
	pTree->Preorder(pTree->GetRoot());
	printf("\n");

	printf("Inorder:\n");
	pTree->Inorder(pTree->GetRoot());
	printf("\n");

	printf("Postorder:\n");
	pTree->Postorder(pTree->GetRoot());
	printf("\n");

	printf("BFS:\n");
	pTree->BFS(pTree->GetRoot());
	printf("\n");

	delete pTree;
}
