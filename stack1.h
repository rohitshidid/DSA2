#include"bst.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
	node *n;
	struct stack *next;
}stack;

typedef stack* ss; 

init_stack(ss *s1){
	(*s1)=  NULL;
}

int isempty(ss s1){
	if(!ss){
		return 1;
	}
	return 0; 
}

void pop(ss *s1){
	(*s1)= (*s1)->next;
}

void push(ss *s1, node *nn){
	ss temp;
	temp = (ss)malloc(sizeof(ss));
	temp->n = nn;
	(*s1)->n = nn;
	(*s1)->next 
	
}