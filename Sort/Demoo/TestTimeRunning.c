#include <stdio.h>
#include <time.h>       
#include <stdlib.h>
#include <string.h>
#define MAX 1000000

int A[MAX];
int Temp[MAX/2+1];
void Swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void BubbleSort(int size)
{
    int sorted = 0;
    for(int i = 0; i < size-1; i++){
        if(sorted == 0){
            sorted = 1;
            for(int j = 0;j < size -i-1; j++){
                if(A[j] > A[j+1]){
                    Swap(&A[j], &A[j+1]);
                    sorted = 0;
                }
            }
        }
    }
}
void InsertionSort(int size)
{
    int k, pos,temp;
    for(k = 1;k<size;k++){
        temp = A[k];
        pos = k;
        while(pos > 0 && A[pos-1] > temp){
            A[pos] = A[pos-1];
            pos = pos - 1;
        }
        A[pos] = temp;
    }
}

void SelectionSort(int size)
{
    int i, j,index_min;
    for(i = 0; i < size - 1; i++){
        index_min = i;
        for(j =i+1;j<size;j++){
            if(A[j] < A[index_min] )
                index_min = j;
        }
        Swap(&A[i],&A[index_min]);
    }
}

void MaxHeapify(int i, int n)
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
        MaxHeapify(indexMax,n);
    }
}

void BuildMaxHeap(int n)
{
    for(int i = n/2;i >= 0;i--)
        MaxHeapify(i,n);
}

void HeapSort(int n)
{
    BuildMaxHeap(n);
    for(int i = n;i>=1;i--){
        Swap(&A[0],&A[i]);
        MaxHeapify(0,i-1);
    }
}

void Merge(int head, int mid, int tail)
{
    
    int head1 = head;
    int tail1 = mid;
    int head2 = mid + 1;
    int tail2 = tail;
    int index = head1;
    for( ; (head1 <= tail1) && (head2 <= tail2) ; index++){
        if(A[head1] < A[head2]){
            Temp[index] = A[head1];
            head1++;
        }
        else{
            Temp[index] = A[head2];
            head2++;
        }
    }
    for( ; head1 <= tail1; head1++,index++)
        Temp[index] = A[head1];
    for( ; head2 <= tail2; head2++,index++)
        Temp[index] = A[head2];
    for(index = head; index <= tail; index++)
        A[index] = Temp[index];
    
}
void MergeSort(int head,int tail)
{
    if(head < tail){
        int mid = (head + tail)/2;
        MergeSort(head,mid);
        MergeSort(mid+1,tail);
        Merge(head,mid,tail);
    }
}

int main()
{

    for(int i = 0; i < 100000; i++){
        A[i] = rand() % 10000;
    }
    
    double time_spent = 0.0;
    clock_t begin = clock();
    // to store the execution time of code
    // do some stuff here
    
    HeapSort(100000);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nThe elapsed time is %f seconds", time_spent);
 
    return 0;
}