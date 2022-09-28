#include<stdio.h>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int PartitionMid(int A[], int left, int right)
{
    int pivot = A[(left + right)/2];
    while(left < right){
        while(A[left] < pivot) left ++;
        while(A[right] > pivot) right --;
        if(left < right){
            Swap(&A[left],&A[right]);
            left++;
            right--;
        }
    }
    return right;
}


void QickSort(int A[], int left, int right)
{
    int index_pivot;
    if(left < right){
        index_pivot = PartitionMid(A,left,right);
        QickSort(A,left,index_pivot-1);
        QickSort(A,index_pivot +1,right);
    }
}


int main()
{
    int A[15] = {12,5,78,25,99,-18,123,-89,70,45,-7,27,78,-1234,98};
    QickSort(A,0,14);
    for(int i = 0; i < 15 ;i++){
        printf("\t%d",A[i]);
    }
}