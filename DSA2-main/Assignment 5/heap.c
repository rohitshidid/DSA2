#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include"heap.h"
#define max_size 40
#define max(a, b) (((a) >= (b)) ? (a) : (b))
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void init_Heap(heap *h)
{
    h->rear = -1;
    h->size = max_size;
    h->A = (int *)malloc(sizeof(int) * h->size);
    return;
}


void traverse(heap h, int ss)
{
    int i = 0;
    int j = 0;
    int end =ss;
    for(int i = 0; i < ss; i++){
        printf("%d ",h.A[i]);
    }
    return;
}





void heapify(heap *h, int index)
{
    int parent = (index - 1) / 2;

    if (h->A[index] > h->A[parent] && index > 0)
    {
        swap(&h->A[index], &h->A[parent]);
        heapify(h, parent);
    }
    return;
}


void insert(heap *h, int data)
{
    if (h->rear == h->size - 1)
        return;
    h->rear++;
    h->A[h->rear] = data;
    int rear_p = (h->rear - 1) / 2;
    if (h->A[h->rear] > h->A[rear_p])
        heapify(h, h->rear);
    return;
}

void remove_heapify(heap *h, int root)
{
    if ((2 * root + 2) > h->rear)
        return;
    int next;
    if (h->A[2 * root + 1] >= h->A[2 * root + 2])
        next = 2 * root + 1;
    else
        next = 2 * root + 2;
    swap(&h->A[root], &h->A[next]);
    remove_heapify(h, next);
    return;
}

int Remove(heap *h)
{
    if (h->rear == -1)
        return INT_MIN;

    int x = h->A[0];
    swap(&h->A[0], &h->A[h->rear]);
    h->rear--;
    remove_heapify(h, 0);
    return x;
}

int get_max(heap h)
{
    if (h.rear == -1)
        return INT_MIN;
    return h.A[0];
}
/*
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


*/