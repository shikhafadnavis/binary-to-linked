/*

Author : Shikha Fadnavis
File   : binary-to-linked.c
Date   : 09/08/2017


*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* pLeft;
	struct node* pRight;
	
}node;

node* insertNode(int value)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = value;
	newNode->pLeft = NULL;
	newNode->pRight = NULL;
	return newNode;


}

node* findNode(node* root, int value)
{
	if(root != NULL)
	{
		if(root->data == value)
		{
			//printf("%d", root->data);
			//printf("\nhere!");
			return root;

		}
		else
		{
			findNode(root->pLeft, value);
			findNode(root->pRight, value);
	
		}

	}
	


}
/*
node* insertLeft(node* root, int value)
{
	node* thisNode = root;
	bool res = false;
	if(thisNode->data == value)
	{
		return thisNode;
	}

	else
	{
		

	}


}

*/

int main()
{
	node* resultNode = NULL;
	node* root = insertNode(1);
	root->pLeft = insertNode(2);
	root->pRight = insertNode(3);
	root->pLeft->pLeft = insertNode(4);
	root->pLeft->pLeft->pLeft = insertNode(7);
	root->pLeft->pLeft->pRight = insertNode(8);
	root->pRight->pLeft = insertNode(5);
	root->pRight->pRight = insertNode(6);
	resultNode = findNode(root, 4);
	if (resultNode)
	{
		printf("heyyyy");
	}
	
	

	return 0;

	
	
	




}

