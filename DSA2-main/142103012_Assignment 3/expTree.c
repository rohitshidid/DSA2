#include <stdio.h>
#include <stdlib.h>
#include "expTree.h"
#include <math.h>
#include <string.h>

int isOperator(char Data){

    if((Data == '+')||(Data == '-')||(Data == '*')||(Data == '/')||(Data == '^'))
        return 1;

    return 0;

}

int LeafNode(node* Node){

    return (!Node -> right)&&(!Node -> left);

}

void inorder(eTree et){

    if(!et)
        return;

    inorder(et -> left);
    printf("%c ", et -> data);
    inorder(et -> right);

    return;

}

node* NewNode(char charac){

    node* nn = NULL;

    nn = (node*)malloc(sizeof(node));
    nn -> data = charac;
    nn -> left = NULL;
    nn -> right = NULL;

    return nn;

}

int Compute(eTree et){

    int result, a, b;

    if(!et)
        return 0;

    if(LeafNode(et))
        return et -> data - '0';

    a = Compute(et -> left);
    b = Compute(et -> right);
       
    return evaluate(et -> data, a, b);
}

int evaluate(char operator, int a, int b){
    
   switch(operator){

        case '+':
            return a + b;

        case '-':
            return a - b;

        case '*':
            return a*b;

        case '/':
            return a/b;

        case '^':
            return a^b;

   }

}

int checkPrecedence(char Op){

    if((Op == '+')||(Op == '-'))
        return 1;

    if((Op == '*')||(Op == '/'))
        return 2;

    if(Op == '^')
        return 3;

    else 
        return 0;

}

eTree init_tree(eTree e, char* string, int start, int end){

    int i = end, j = end;

    if(start == end){
        return NewNode(string[start]);
    }

    while(i >= start){

        if(isOperator(string[i])&&(isOperator(string[j]))&&(checkPrecedence(string[j]) <= checkPrecedence(string[i]))){

            break;

        }
        else if(isOperator(string[i])){
            j = i;
        }

        i--;
    }
    
    e = NewNode(string[j]);

    e -> left = init_tree(e, string, start, j - 1);
    e -> right = init_tree(e, string, j + 1, end);
    return e;

}

eTree Init(eTree e, char *string){

    e = init_tree(e, string, 0, strlen(string) - 2);

    return e;

}
