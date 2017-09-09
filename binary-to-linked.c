/*

Author : Shikha Fadnavis
File   : binary-to-linked.c
Date   : 09/08/2017


*/

#include<stdio.h>
#include<stdlib.h>
#define ARRSIZE 50
//This limits the number of elements in binary tree to 50. Please change it accordingly.


typedef struct node
{
	int data;
	struct node* pLeft;
	struct node* pRight;
	
}node;

node* inorderArr[ARRSIZE];

int arrIndex = 0;


node* insertNode(int value)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = value;
	newNode->pLeft = NULL;
	newNode->pRight = NULL;
	return newNode;


}


void inorder(node* root)
{
	if (root != NULL)
	{
		inorder(root->pLeft);
		inorderArr[arrIndex] = root;
		arrIndex += 1;
		inorder(root->pRight);

	}

	else
	{
		return;
	} 

}

void convertBinaryToLinked(node* head, int i)
{

	if(i < arrIndex && head != NULL)
	{
		if(i == 0)
		{
			head->pLeft = NULL;
			head->pLeft = inorderArr[i+1];
		}
		if(i == arrIndex-1)
		{
			head->pLeft = inorderArr[i-1];
			head->pRight = NULL;
		}
		else
		{	
			head->pLeft = inorderArr[i-1];
			head->pRight = inorderArr[i+1];
		}

		convertBinaryToLinked(head->pRight, i+1);

	}

	else
	{
		return;
	}
		

}


int main()
{
	
	int i = 0;
	int counter = 0;
	for(i = 0; i < ARRSIZE; i++)
	{
		inorderArr[i] = NULL;
	}

	// create a binary tree
	node* root = insertNode(1);
	root->pLeft = insertNode(2);
	root->pRight = insertNode(3);
	root->pLeft->pLeft = insertNode(4);
	root->pLeft->pLeft->pLeft = insertNode(7);
	root->pLeft->pLeft->pRight = insertNode(8);
	root->pRight->pLeft = insertNode(5);
	root->pRight->pRight = insertNode(6);
	root->pLeft->pLeft->pRight->pLeft = insertNode(10);
	root->pLeft->pLeft->pRight->pRight = insertNode(11);

	

	// Store pointer to each node in an array in an Inorder fashion
	inorder(root);
	
	// Call the recursive function to convert Binary Tree into a Doubly Linked List
	convertBinaryToLinked(inorderArr[0], counter);
	
	node* head = inorderArr[0];
	printf("Head Node is : %d\n", head->data);
	
	// To view the list in forward direction
	printf("List contents:\n");
	while(head!=NULL)
	{
		printf("%d\n", head->data);
		head = head->pRight;
	}

	
		
	return 0;

	

}



