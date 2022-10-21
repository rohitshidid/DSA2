#include <stdio.h>
#include "expTree.h"

int main(){

    eTree et;
    char infix[100];
    int result = 0;

    printf("Enter the infix expression\n");
    fgets(infix, 100, stdin);

    et = Init(et, infix);
   
    result = Compute(et);
    printf("\nThe required result is %d\n",result);

    printf("Inorder Traversal -> \n");
    inorder(et);
    return 0;

}
