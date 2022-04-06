#include<stdio.h>
typedef struct node{
int data;
struct node *right,*left;

}node;

typedef node* bst;

void init_bst (bst *t);

void insert_node(bst *t, int d);

void traverse(bst t);
