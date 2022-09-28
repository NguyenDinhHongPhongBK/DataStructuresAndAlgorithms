#include<stdio.h>

int A[1000000];

void Swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void SelectionSort(int A[],int size)
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
    SelectionSort(A,n);
    //printf("\nArray after sort : \n");
    for(int i=0;i<n;i++){
        printf("%d",A[i]);
    }

}