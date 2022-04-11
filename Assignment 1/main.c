#include <stdio.h>
#include"bst.h"

int main(){

    bst t1;
    init_tree(&t1);
    insert_node(&t1,12,"rohit");
    insert_node(&t1,8,"viren");
    insert_node(&t1,9,"simple");
    insert_node(&t1,7,"simple");
    
    printf("\n Displaying tree\n");
    postorder(t1);
    
    //search
    printf("\n \nSearch Results are : \n");
    search(t1,11);
    
    //display_level(t1,1)
    printf("\n \nDisplay Level\n");
    display_level(t1,3);


    //delete node
    printf("\n \nDelete Node: \n");
    delete_node(&t1,12);
    postorder(t1);
    delete(&t1);
    postorder(t1);
    
    

}

