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
    if(t==NULL){
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

void destroy(bst *t){
    if(!(*t)){
        return;
    }
    destroy(&(*t)->left);
    destroy(&(*t)->right);
    free((*t));
    (*t) =NULL;
    //printf("Node deleted");
}


void display_level(bst t,int lev){
    
    if(!t)
    return;

    if(lev == 1){
        printf("MIS: %d  NAME: %s \n",t->mis,t->name);
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

    // rootnode with zero child
    if(p->mis == key && q==NULL && p->left==NULL &&p->right==NULL){
	free(p);
	p = NULL;
	return;
    }
    // root with one child
    if(p->mis == key && q == NULL && p->left){
        q = p;
        p = p->left;
        free(q);
	return;
    }
    if(p->mis == key && q == NULL && p->right){
	q=p;
	p=p->right;
	free(q);
	return;
   }

    // leaf nodes
   while(1){	   
     if(key > p->mis &&p->right){
    	q=p;
	p=p->right;
    }
     if(key < p->mis && p->left){
	q=p;
	p=p->left;
     }

    if(p->right == NULL && p->mis == key && p->left==NULL){
	p=NULL;
	free(p);
	printf("Leaf node deleted successfully");
	return;
   
    }
    // node in middle with some child node
    if(p->mis == key &&(p->right || p->left)){
	
	// one child node
	if (p->right && !p->left){
		q = p->right;
		p->right=p->right->right;
		free(q);
		q=NULL;
	}
	if(p->left && !p->right){
		q= p->left;
		p->left = p->left->left;
		free(q);
		q=NULL
	}

	// Multiple node
	// code from here

    }

   }

    
   
   
	

}
