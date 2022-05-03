#include <stdio.h>
#include <stdlib.h>
#include "postorder.h"
int main()
{
  bst t1;
  initbst(&t1);
  int *ptr = NULL;
  int size;
  printf("Enter the number of elements : ");
  scanf("%d", &size);
  int * arr = inputbst(ptr, size);
  for (int i = 0; i < size; i++)
  {
    printf("%d ", *(arr+i));
  }
  printf("\nEntering data in nodes.. \n");
  for (int i = size-1; i >= 0; i--)
  {
    createNode(&t1, arr[i]);
  }
  printf("\nInorder\n");
  inorder(t1);
  printf("\nPreorder\n");
  preorder(t1);
  
  return 0;
}