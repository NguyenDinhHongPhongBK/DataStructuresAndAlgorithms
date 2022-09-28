#include<stdio.h>

int A[1000000];

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

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    
    InsertionSort(n);
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }

}