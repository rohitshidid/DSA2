#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
    int data;
    struct Node *left, *right,*parent;

}Node;

typedef Node *bst;

void init_bst(bst *t){
    (*t)=NULL;
}

void insert_node(bst *t, int val){
    
    
    
    Node *temp, *p, *q;
    
    temp  = malloc(sizeof(Node));
    temp->data = val;
    temp->left= NULL;
    temp->right = NULL;
    temp->parent = NULL;
    if(!temp){
        printf("ERROR");
        return;
    }
    
    if (!(*t)) (*t)=temp;
    p = (*t);
    
    if(p->data == val) return;
    if(p->data < val && p->right){
        p=p->right;
        insert_node((&p), val);
    }
    if(p->data > val&& p->left){
         p=p->left; 
         insert_node((&p), val);
    }
    if(p->data < val && !p->right){
        p->right = temp; 
        temp->parent = p;
        return;
    }
    if(p->data > val && !p->left){
        p->left = temp;
        temp->parent = p;
        return;
    }
    

}


void inorder(bst t){
    if(!t) return;
    
    if(t->left)
    inorder(t->left);
    printf("%d \t",t->data);
    if (t->right)
    inorder(t->right);
    
    
}

void search(bst t, int key){
    if(!t) return;
    if(t->data == key){
        printf("\n %d  was found ", t->data);
    return;
    }
    if(key>t->data){
        search(t->right,key);
    }
    if(key<t->data)
    search(t->left,key);

    return;

}

void postorder(bst t){
    if(!t) return;

    while(t){
        if(t->left) {
            t=t->left;
        }
        else if (t->parent->right) {
            t=t->parent->right;
        }
        else {
            t=t->parent;
        }

        printf("%d",t->data);
    }
}



void display_level(bst t, int level){
    if(!t) return;
    int i =0;
    Node *p;
    p = t;
    if(level==0){
        printf("%d",t->data);
        return;
    }
    if(level==1) i =1;
    while( i < level-1 && t!=NULL &&t->left != NULL){

        t=t->left;
        i++;
    }
    
    if(t->left){
    printf("%d",t->left->data);
    
    }
    
    if(t->right)
    printf("%d",t->right->data);
    
    if(level==1) return;
    i=0;


    while( i < level-1 && p!=NULL && p->right != NULL){
        p = p->right;
        i++;
    }

    if(p->left)
    printf("%d",p->left->data);

    if(p->right)
    printf("%d",p->right->data);
    
    return;
    
}



