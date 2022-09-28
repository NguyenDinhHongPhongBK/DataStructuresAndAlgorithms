#include<stdio.h>

int n,m,x[100],a[100];
int count=0;
int T=0;
int k=1;

int Sum(){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=x[i]*a[i];
    }  
    return sum;
}

void Results(){
    printf("%d)",k);
    printf("\t");
    for(int i=1;i<=n;i++){
        printf("%d\t",x[i]);
    }     
    k++;
}

int Try(int k){
    for(int v=1;v<m;v++){
        x[k]=v;
        if(k==n){
           if(Sum()==m){
               Results();
               printf("\n");
               count++;
           }
        }else{
            Try(k+1);
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    Try(1);
    if(count==0){
        printf("No results");
    }
}