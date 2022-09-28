#include<stdio.h>
int A[1000000];
int main()
{
    
    int m,count = 0;
    scanf("%d",&m);
    for(int i = 0;i< m;i++)
        scanf("%d",&A[i]);
    for(int j = 1; j < m-1; j++){
        if(A[j] > A[j-1] && A[j] > A[j+1]){
            count++;
        }
    }
    printf("%d",count);
}