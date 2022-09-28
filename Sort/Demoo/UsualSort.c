#include<stdio.h>

void Swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void Sort(int A[],int size)
{
    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1;j < size; j++){
            if(A[j] <A[i])
                Swap(&A[j],&A[i]);
        }
    }
}

int main()
{
    int n;
    int A[100];
    //printf("Enter number of elements in this array : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        //printf("Term %d : ",i+1);
        scanf("%d",&A[i]);
    }
    // for(int i=0;i<n;i++){
    //     printf("\t%d",A[i]);
    //}
    Sort(A,n);
    //printf("\nArray after sort : \n");
    for(int i=0;i<n;i++){
        printf("%d",A[i]);
    }

}