#include<stdio.h>
#include"bst.h"

int main(){
    bst t1;
    init_bst(&t1);
    insert_node(&t1,80);
    insert_node(&t1,70);
    insert_node(&t1,100);
    insert_node(&t1,90);
    insert_node(&t1,120);
    insert_node(&t1,85);
    insert_node(&t1,62);
    insert_node(&t1,32);
    insert_node(&t1,15);

    //inorder(t1);
    search(t1,232);

    postorder(t1);
    //display_level(t1,3);
}