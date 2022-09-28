#include<stdio.h>

int n;
int x[100];

int check(int v,int k){
    if(k==1)
        return 1;
    return (v+x[k-1])<=1;
    
}

void solution(int x[]){
    for(int i=1;i<=n;i++){
        printf("%d",x[i]);
    }
}

void Try(int k)
{
    int v;
    for(v=0;v<=1;v++){
        if(check(v,k)){
            x[k]=v;
            if(k==n){
                solution(x);
                printf("\n");
            }
            else{
                Try(k+1);
            }
        }
    }
}

int main(){
    scanf("%d",&n);
    Try(1);
}