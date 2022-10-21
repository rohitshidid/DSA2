#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int mis;
    char name [20];
    struct Node *parent, *left,*right;

}node;
// fixed the issue
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


/*
void postorder(bst t){
    if(t==NULL){
        return;
    }
    if(t->left)
    postorder(t->left);
    if(t->right)
    
    postorder(t->right);
    printf("%d \t %s\n",t->mis,t->name) ;
}*/



void delete_node(bst* t,int key){

    if((*t) == NULL){

        return;
    }
    if((*t)->left == NULL && (*t)->right == NULL && (*t)->parent==NULL){
        (*t)=NULL;
        return;
    }

    node* temp = (*t);
    node* p;

    while(temp){

        if(temp ->mis == key){
            break;
        }
        else if(temp ->mis > key){
            temp = temp ->left;
        }
        else{
            temp = temp ->right;
        }
    }
    if(!temp)
        return;

    if(temp ->left == temp ->right){

         p = temp->parent;
        
        if(p->left == temp){
            p->left = NULL;
            free(temp);
            return;
        }
        p->right = NULL;
        free(temp);
        return;
        
    }
    if(temp->right && !temp->left){
        p= temp->parent;
        if(p->right == temp){
            p->right=temp->right;
            free(temp);
            return;
        }
        p->left =temp->right;
        free(temp);
        return;

    }
    if(!temp->right && temp->left){
        p= temp->parent;
        if(p->right == temp){
            p->right=temp->left;
            free(temp);
            return;
        }
        p->left =temp->left;
        free(temp);
        return;
        
    }

    if(temp->right && temp->left){
        p=temp->right;
        node* m = p;
        if(!p->left){
            temp->mis = p->mis;
           strcpy(temp->name,p->name);
           temp->right = p->right;
           free(p);
           return;
        }
        while(m->left != NULL){
            m = m->left;
        }
        temp->mis = m->mis;
        strcpy(temp->name,m->name);
        free(m);
        return;


    }


}





// Stack type
typedef struct stack{

	node* n;
	struct stack* next;
}stack;

void initStack(stack** s){
	
	*s = NULL;
	return;
}


void push(stack** s,node** temp){

	if(*s == NULL){
		
		stack* p = (stack*) malloc (sizeof(stack));
		if (!p)
			return;
		p-> n = (*temp);
		p -> next = NULL;
		(*s) = p;
		return;
	}
	
	stack* p = (stack*) malloc (sizeof(stack));
	if (!p)
		return;
	p -> n = *temp;
	p -> next = *s;
	*s = p;


}

node* peek(stack* s){
	
	return(s->n);
}

int isEmpty(stack* s){
	
	if(s == NULL){
		return 1;
	}

	return 0;
}

node* pop(stack** s){
	
	node* temp = (*s) -> n;
	(*s) = (*s) -> next;

	return temp;
}

void postorder(bst t){

	if(!t)
		return;
	
	node* previous = NULL;
	stack* ss;
	initStack(&ss);
	while(1){
		while(t != NULL){
			push(&ss,&t);
			t = t ->left;
		}
		while( t == NULL && !isEmpty(ss)){
			t = peek(ss);
			if(t -> right == NULL || t -> right == previous){

				t = pop(&ss);
				previous = t;
				printf("\nMIS = %d ",t ->mis);
				printf("\tName = %s ",t ->name);
				printf("\n");
				t = NULL;
			}
			else
				t = t ->right;
		}
		if(isEmpty(ss))
			return;
	}
}
