#include <stdio.h>

int a[100],x[100];
int L[100],U[100];
int m,n,count = 0;

int Sum(){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=x[i]*a[i];
    }
    return sum;
}
int Test(int v,int k){
    for(int i=0;i<n;i++){
        if(v < L[k] || v > U[k])
            return 0;
    }
    return 1;
}

void Results(){
    for(int i=0;i<n;i++){
        printf("%3d",x[i]);
    }
    printf("\n\n");
}

void Try(int k){
    for(int v=1;v<m;v++){
        if(Test(v,k)){
            x[k] = v;
            if(k==n-1){
                if(Sum() == m)
                    count++;
            }else{
                Try(k+1);
            }
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d%d",&L[i],&U[i]);
    }
    Try(0);
    printf("%d",count);
}