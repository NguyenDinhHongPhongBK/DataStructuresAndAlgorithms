#include<stdio.h>

int A[1000000];

void Swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void BubbleSort(int A[],int size)
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

int main()
{
    int n;
    // printf("Enter number of elements in this array : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        // printf("Term %d : ",i+1);
        scanf("%d",&A[i]);
    }
    // for(int i=0;i<n;i++){
    //     printf("\t%d",A[i]);
    // }
    BubbleSort(A,n);
    // printf("\nArray after sort : \n");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }

}