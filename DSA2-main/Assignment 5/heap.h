
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define max_size 40
#define max(a, b) (((a) >= (b)) ? (a) : (b))

typedef struct heap
{
    int *A;
    int size, rear;
} heap;

void swap(int *a, int *b);


void init_Heap(heap *h);

void traverse(heap h,int ss);


void heapify(heap *h, int index);


void insert(heap *h, int data);


void remove_heapify(heap *h, int root);


int Remove(heap *h);


int get_max(heap h);


//void HeapSort(int *arr, int s);


