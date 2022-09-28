#include<stdio.h>
#define N 100

int n;
int x[N];
int appear[N];

int check(int v){
    return appear[v] == 0;
}

void solution(int x[]){
    for(int i=1;i<=n;i++){
        printf("%d",x[i]);
    }
}

void Try(int k)
{
    int v;
    for(v=1;v<=n;v++){
        if(check(v)){
            x[k]=v;
            appear[v]=1;
            if(k==n){
                solution(x);
                printf("\n");
            }
            else{
                Try(k+1);
            }
            appear[v]=0;
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        appear[i]=0;
    Try(1);
}