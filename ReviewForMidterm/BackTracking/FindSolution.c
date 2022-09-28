#include<stdio.h>
#include<stdlib.h>

int n,M;
int x[100], A[100];
int count = 0;

int Test(int v, int k)
{
    if(k < n)
        return 1;
    else{
        int t = 0;
        for(int i = 1;i < n;i++)
            t += A[i]*x[i];
        return t + v*A[k] == M;
    }

}

void Results()
{
    printf("\t\t\t");
    for(int i = 1;i <= n;i++){
        if(i == n){
        printf("%d * %d\t   =\t%d",x[i],A[i],M);
        }else{
            printf("%d * %d\t   +\t",x[i],A[i]);
        }
    }
    printf("\n");
}

void Try(int k)
{
    for(int v = 1;v <= M;v++){
        if(Test(v,k)){
            x[k] = v;
            if(k == n){
                Results();
            }else{
                Try(k+1);
            }
        }
    }
}

int main()
{
    printf("\tEnter number of variables : ");
    scanf("%d", &n);
    for(int i = 1;i <= n;i++){
        printf("\tEnter value of variable %d : ",i);
        scanf("%d",&A[i]);
    }
    printf("\tEnter number of value in right handside : ");
    scanf("%d",&M);
    Try(1);
}