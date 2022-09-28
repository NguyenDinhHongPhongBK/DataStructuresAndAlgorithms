#include<stdio.h>

void Swap(int *a, int *b)
{
    int c = *a;*a = *b;*b = c;
}

void MaxHeapify(int A[], int i, int n)
{
    int leftChild = 2*i;
    int rightChild = 2*i+1;
    int indexMax = i;
    if(leftChild <=n && A[leftChild] > A[indexMax]) 
        indexMax = leftChild;
    if(rightChild <=n && A[rightChild] > A[indexMax]) 
        indexMax = rightChild;
    if(indexMax != i){
        Swap(&A[i],&A[indexMax]);
        MaxHeapify(A,indexMax,n);
    }
}

void BuildMaxHeap(int A[], int n)
{
    for(int i = n/2;i >= 0;i--)
        MaxHeapify(A,i,n);
}

void HeapSort(int A[], int n)
{
    BuildMaxHeap(A,n);
    for(int i = n;i>=1;i--){
        Swap(&A[0],&A[i]);
        MaxHeapify(A,0,i-1);
    }
}

int main()
{
    int A[] = {12,-4,8,70,-90,23,15};
    HeapSort(A,7);
    for(int i = 0;i<7;i++){
        printf("%d\t",A[i]);
    }
}