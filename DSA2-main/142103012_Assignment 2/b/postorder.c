#include <stdio.h>
#include <stdlib.h>
#include "postorder.h"


void initbst(bst *tree)
{ 
  *tree = NULL;
  return;
}

void createNode(bst *tree, int d)
{
  node *nn = (node *)malloc(sizeof(node));
  nn->data = d;
  nn->left = NULL;
  nn->right = NULL;

  if (!(*tree))
    *tree = nn;
  node *temp = *tree;

  if (d < temp->data)
    createNode(&(temp->left), d);
  else if (d > temp->data)
    createNode(&(temp->right), d);
  else if(d == temp->data)
    return;
  
}

int *inputbst(int *arr, int size)
{
  arr = (int *)calloc(size, sizeof(int));
  for (int i = 0; i < size; i++)
    scanf("%d", &arr[i]);
  return arr;
}

void inorder(bst tree)
{
  if (!tree)
    return;
  inorder(tree->left);
  printf("%d ", tree->data);
  inorder(tree->right);
}

void preorder(bst tree)
{
  if (!tree)
    return;
  printf("%d ", tree->data);
  preorder(tree->left);
  preorder(tree->right);
}

