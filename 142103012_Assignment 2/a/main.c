#include"bst.h"
int main(){
bst t;
int cho;
    while(1){
        printf("\n\n\n1) Init tree\n2) Insert Data\n3) Traverse\n4) Iscomplete\n5) Exit\nSelect your choice ");
        scanf("%d",&cho);
        switch(cho){
            case 1: init(&t);
            break;
            case 2: printf("Enter the data to be inserted ");
            int dat;
            scanf("%d",&dat);
            insert_data(&t,dat);
            break;
            case 3: printf("\n1) Preorder\n2) Inorder\n3) Postorder\nSelect the order ");
            scanf("%d",&cho);
            printf("\nPrinting Your Choice \n");
            if(cho == 1)
            preorder(t);
            if(cho == 2)
            inorder(t);
            if(cho ==3)
            postorder(t);
            if(cho != 2 && cho != 1 && cho!=3)
            printf("\nInvalid choice");
            break;
            case 4: 
            printf("\n");
            iscomplete(t);
            break;
            case 5: exit(0);
            default: printf("Invalid Option! ");
        
        
        }

        
    }
}