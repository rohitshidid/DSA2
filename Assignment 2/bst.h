#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int size;
    int arr[];
}node;

typedef node* bst;

void init(bst *t){
   int size  = 100;
    (*t) = malloc(sizeof(bst)) + (sizeof(int)*size);
    if(!(*t))
        return;
    (*t) ->size = size;
    node *temp = (*t);
    for(int i =0;i<size;i++){
        temp->arr[i]=INT8_MIN;
    }
}


void insert_data (bst (*t), int data){
    if(!(*t))
        return;
    
    node *temp = (*t);
    int n = temp->size;
    int i = 0;
    while(i<n){
        if(temp->arr[i]==data){
        printf("Data Already Exists\n");
        return;
        }
        if(temp->arr[i]==INT8_MIN){
            temp->arr[i]=data;
            printf("Data Inserted successfully\n");
            return;
        }
        else if (data > temp->arr[i])
        {
            i = 2*i+2;
        }else{
            i = i*2+1;
        }
    }
}

void preorder_h(bst t ,int n , int i){
    if(t->arr[i]==INT8_MIN)
    return;
    printf("%d\t",t->arr[i]);
    preorder_h(t,n,2*i+1);
    preorder_h(t,n,2*i+2);
    
}

void preorder(bst t){
    int i = 0;
    int n = t->size;

    if(!t)
    return;

    preorder_h(t,n,i);
}

void postorder_h(bst t ,int n,int i){
    if(t->arr[i]==INT8_MIN)
    return;
    postorder_h(t,n,2*i+1);
    postorder_h(t,n,2*i+2);
    printf("%d\t",t->arr[i]);
}
void postorder(bst t){
    if(!t)
    return;

    int i = 0;
    int n = t->size;
    postorder_h(t,n,i);
}

void inorder_h(bst t,int n, int i){
    if(t->arr[i]==INT8_MIN)
    return;
    inorder_h(t,n,2*i+1);
    printf("%d\t",t->arr[i]);
    inorder_h(t,n,2*i+2);
}

void inorder(bst t){
    if(!t)
    return;
    int i =0;
    int n = t->size;
    inorder_h(t,n,i);
}



void iscomplete(bst t){
    int i = 0;
    int n = t->size;
    int c = 0;
    int m = 0;
    if(!t)
    return;
    for(i = 0; i < n ; i++){
        if(t->arr[i]!=INT8_MIN){
        c++;
        m = i;
        }   
    }
    if(m<c)
    printf("Tree is Complete");
    else
    printf("Tree is incomplete");
}