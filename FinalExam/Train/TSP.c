#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n;
int Appear[100];
int A[100][100];
int x[100];
int min = 2147483647;
int sum = 0;

int Check(int v, int k){
    return Appear[v] == 0;
}

void TSP(int k)
{
    for(int v = 2;v <=n;v++){
        if(Check(v,k) && sum < min){
            x[k] = v;
            Appear[v] = 1;
            if(k ==n){
                sum += A[x[k-1]][x[k]] + A[x[k]][1];
                if(sum < min)
                    min = sum;
            }
            else{
                if(k == 2)
                    sum += A[1][x[k]];
                else
                    sum += A[x[k-1]][x[k]];
                TSP(k+1);
            }
            Appear[v] = 0;
            if(k == 2)
                sum -= A[1][x[k]];
            else if(k == n)
                sum -= (A[x[k-1]][x[k]] + A[x[k]][1]);
            else
                sum -= A[x[k-1]][x[k]];
        }
    }
    
}

int main()
{
    for(int  i =0;i<100;i++)
        Appear[i] = 0;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            scanf("%d",&A[i][j]);
        }
    }
    TSP(2);
    printf("%d",min);
}