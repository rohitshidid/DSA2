#include <stdio.h>
#include"bst.h"

int main(){

    bst t1;

    //init
    init_tree(&t1);
    
    //insert
    insert_node(&t1,17,"shitij");
   /* insert_node(&t1,2,"anuj");
    insert_node(&t1,43,"nupur");
    insert_node(&t1,45,"prathamesh");
    insert_node(&t1,6,"pallavi");
    insert_node(&t1,11,"vedanti");
    insert_node(&t1,67,"viren");
    insert_node(&t1,44,"shubham");
    insert_node(&t1,9,"aneerban");
    insert_node(&t1,10,"Aditya");
    insert_node(&t1,15,"arjun");
    insert_node(&t1,12,"Rohit");
  */
    
    //display
    printf("\nDisplaying tree\n");
    postorder(t1);
    
    //search
    printf("\n \nSearch Results are : \n");
    search(t1,12);
    
    //display_level(t1,1)
    printf("\n \nDisplay Level\n");
    display_level(t1,3);


    //delete node
    printf("\n \nDelete Node: \n");
    delete_node(&t1,17);
    printf("After deletion\n");
    postorder(t1);




    // delete tree
    printf("\n \nDeleting Tree: \n");
    destroy(&t1);
    printf("\n\nPrinting Tree after deleting: \n");
    postorder(t1);
    
    

}

