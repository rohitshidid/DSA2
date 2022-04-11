#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    int mis;
    char name [20];
    struct Node *parent, *left,*right;

}node;

typedef node *bst;

void init_tree(bst *t){
    (*t) = NULL;

}

void insert_node(bst *t, int mis, char name[20]){

    node *temp,*p;
   
    temp = malloc(sizeof(node));
    temp->mis = mis;
    strcpy(temp->name,name);
    temp->parent = NULL;
    temp->left= NULL;
    temp->right = NULL;


    if(!(*t)) 
    (*t)= temp;
     p = (*t);
    if(mis < p->mis && p->left){
        p=p->left;
        insert_node(&p,mis,name);
    }
    if(mis > p->mis && p->right){
        p=p->right;
        insert_node(&p,mis,name);
    }
    if(p->mis < mis && !p->right){
        p->right = temp; 
        temp->parent = p;
        return;
    }
    if(p->mis > mis && !p->left){
        p->left = temp;
        temp->parent = p;
        return;
    }

}

void postorder(bst t){
    if(!t){
        return;
    }
    if(t->left)
    postorder(t->left);
    if(t->right)
    postorder(t->right);
    printf("%d \t %s\n",t->mis,t->name) ;
}


void search(bst t, int mis){
    if(!t) return;
    if(t->mis == mis){
        printf("\n %d  was found name is: %s \n ", t->mis, t->name);
    return;
    }
    if(mis>t->mis){
        search(t->right,mis);
    }
    if(mis<t->mis)
    search(t->left,mis);

    return;

}

void delete(bst *t){
    if(!(*t)){
        return;
    }
    if((*t)->left){
        (*t)=(*t)->left;
    }
    if((*t)->right){
        (*t)=(*t)->right;
    }
    free((*t));
    (*t)=NULL;
}


void display_level(bst t,int lev){
    
    if(!t)
    return;

    if(lev == 1){
        printf("MIS: %d  NAME: %s \n ",t->mis,t->name);
    }
    if(lev > 1){
        if(t->left)
        display_level(t->left,lev-1);
        if(t->right)
        display_level(t->right,lev-1);
    }
}


void delete_node(bst *t, int key){
    if((*t)==NULL)
    return;

    node *p,*q;
    p=(*t);
    q = NULL;
    if(p->mis == key && q == NULL && p->left){
        q = p;
        p = p->left;
        
        free(q);
    }
    
}