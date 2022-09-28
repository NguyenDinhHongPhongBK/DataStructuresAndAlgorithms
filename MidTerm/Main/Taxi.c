#include<stdio.h>
#include<stdlib.h>

int A[1000][1000];
int appear[100], x[100], n;
int min = 100000,sum = 0;
int check(int v,int k){
    return appear[v] == 0;
}

void Try(int k)
{
    int v;
    for(v=1;v<=n;v++){
        if(check(v,k)){
            x[k]=v;
            appear[v]=1;
            if(k==n){
                int sum = 0;
                for(int i=1;i<=n;i++){
                    if(i == 1)
                        sum += A[0][x[i]] + A[x[i]][x[i] + n];
                    else if(i == n)
                        sum += A[x[i-1] + n][x[i]] + A[x[i]][x[i] + n] + A[x[i] + n][0]; 
                    else 
                        sum += A[x[i-1] + n][x[i]] + A[x[i]][x[i] + n]; 
                }
                if(sum <min)
                    min = sum;
            }
            else{
                Try(k+1);
            }
                appear[v]=0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        appear[i]=0;
    
    for(int j = 0;j < 2*n + 1;j++){
        for(int s = 0;s < 2*n + 1;s++){
            scanf("%d",&A[j][s]);
        }
    }
    Try(1);
    printf("%d",min);
}