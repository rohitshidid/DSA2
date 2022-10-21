
#include"heap.h"

void HeapSort(int *arr, int s)
{
    heap h;
    init_Heap(&h);
    for (int i = 0; i < s; i++)
    {
        insert(&h, arr[i]);
    }
    for (int i = s - 1; i >= 0; i--)
    {
        arr[i] = Remove(&h);
    }
    return;
}
int main()
{
    heap h;
    int i = 0; 
    int data[1000000];
    init_Heap(&h);
    FILE *fp = fopen("numbers.txt","r");
    while (fscanf(fp,"%d",&data[i])!=-1){
      i++;
  }
  i =0;
    while(data[i]){
        insert(&h,data[i]);

        i++;
    }
    printf("\nPrint Graph Traversal array\n");
    traverse(h,i-1);
    printf("\n");
    int len = i;
    i = 0;
    
    printf("\nSorting the list \n");

    HeapSort(data, len);
    for (int i = 0; i < len; i++)
     {
         printf("%d ", data[i]);
     }
     printf("\n");

}
