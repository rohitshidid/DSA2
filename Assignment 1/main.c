#include <stdio.h>
#include"bst.h"

int main(){
    bst t1;

    //init
    init_tree(&t1);
  while(1){
    printf("\n1) Insert \n2) Delete\n3) Display\n4) Level Display\n5) Search \n6) Delete Tree \n7) Exit \n Enter your choice: ");
    int choice;
    scanf("%d",&choice);
    
    switch (choice)
    {
    case 1: printf("Enter the name ");
            char name[40];
            int mis;
            scanf("%s",name);
            printf("Enter MIS: ");
            scanf("%d",&mis);
            insert_node(&t1,mis,name);
            
  
            break;
    case 2: printf("Enter the mis to delete: ");
            scanf("%d",&mis);
            delete_node(&t1,mis);
            break;
    case 3: printf("\nDisplaying tree\n");
            postorder(t1);
            break;
    case 4: printf("Enter the level to display: ");
            scanf("%d",&mis);
            display_level(t1,mis);
            break;
    case 5: printf("Enter the MIS to be searched: ");
            scanf("%d",&mis);
            search(t1,mis);
            break;
    case 6: destroy(&t1);
            printf("Tree Deleted Sucessfully");
            break;
    case 7:   exit(0);
    default:  printf("Select the given choice");
    break;

   
    }
   
    
    //insert
    /*insert_node(&t1,17,"shitij");
            insert_node(&t1,2,"anuj");
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
  


   
    
  }    

}

