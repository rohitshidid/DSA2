#include<stdio.h>
#include "bst.c"
#include<stdlib.h>

int main(){
bst t1;
init_bst(&t1);
insert_node(&t1,23);
insert_node(&t1,23);
traverse(t1);
}
