#include<stdio.h>
#include "Avl.h"

int main(){
    AVL root;
    InitAvl(&root);
    printf("Welcome....\n");
     while(1){
        int command=0;
        printf("\n\n\n++++++++++++++ Menu Options ++++++++++++++\n");
        printf("1.Insert all Months in Tree\n2.To remove Months\n3.To display all months in a Tree\n4.To delete all month in Tree\n5.Exit\n\n");
        scanf("%d",&command);
        if(command<1 || command>5){
            printf("Enter a valid number to proceed.....");
            continue;
        }
        switch (command){
            char month[10];
            int level;
            case 1: 
                InsertNode(&root,"Mar");
                InsertNode(&root,"Feb");
                InsertNode(&root,"Jan");
                InsertNode(&root,"Apr");
                InsertNode(&root,"May");
                InsertNode(&root,"Jun");
                InsertNode(&root,"Jul");
                InsertNode(&root,"Aug");
                InsertNode(&root,"Sept");
                InsertNode(&root,"Oct");
                InsertNode(&root,"Nov");
                InsertNode(&root,"Dec");
                printf("All months succesfully inserted");
                break;
            case 2:
                printf("Enter Month to delete: ");
                scanf("%s",month);
                RemoveNode(&root,month);
                break;
             case 3:
                Traverse(root);
                printf("\nTraversal completed sucessfully!... \n");
                break;
             case 4:
               Destroy(&root);
               printf("\nAll the Nodes deleted sucessfully!...\n");
                break;
            
            default:
            	printf("\nSelect from given choice.");
                break;
        }
        if(command==5) 
           break;
    }
    printf("\nProgram exited sucessfully");
    
    return 0;
}
