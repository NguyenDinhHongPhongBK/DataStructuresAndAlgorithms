#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define M 100000

int A[M];
int n;
int Frog[M];

int Min(int a,int b)
{
    return a<=b?a:b;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0;i < n;i++){
        scanf("%d", &A[i]);
    }
    Frog[0]=0;
    Frog[1]=abs(A[0]-A[1]);
    Frog[2]=abs(A[2]-A[0]);
    for(int i=3;i<n;i++){
        Frog[i]=Min(Frog[i-1]+abs(A[i]-A[i-1]),Frog[i-2]+abs(A[i]-A[i-2]));
    }
    printf("%d",Frog[n-1]);
}