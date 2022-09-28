#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int A[10000][3],n;
int x[10000];
int max = 0;
int Check(int v, int k)
{
    if(k == 1)
        return 1;
    else{
        if(v != x[k-1])
            return 1;
    }
    return 0;
}

void Vacation(int k)
{
    for(int v = 1; v <= 3; v++){
        if(Check(v,k)){
            x[k] = v;
            if(k == n){
                int sum = 0;
                for(int i = 1; i <= n; i++)
                    sum +=A[i][x[i]];
                if(sum > max) 
                    max = sum;
            }
            else{
                Vacation(k+1);
            }
            
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 3; j++){
            scanf("%d", &A[i][j]);
        }
    }
    Vacation(1);
    printf("%d",max);
    
}