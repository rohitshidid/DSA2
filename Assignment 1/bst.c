#include "bst.h"
#include<stdio.h>
#include<stdlib.h>

void init_bst(bst *t){
(*t) = NULL;
return;


}

void insert_node(bst *t, int d){
	
	node *temp;
	temp = malloc(sizeof(node));


	if ((*t) == NULL)
	{
	
		temp->data = d;
		temp->right = NULL;
		temp->left=NULL;
		(*t) = temp;
	}
	else{
		if(d == temp->data)
		printf("Node ALready inserted");
		else if(d > temp->data){
		
		}
	}

}


void traverse(bst t){
	if(t==NULL){
		printf("Tree is Empty");

	}else{

		printf("%d", t->data);


	}
}
