#include <stdio.h>
int m,n,a[100];

void Results(){
    for(int i=1;i<=m;i++){
        printf("%d\t",a[i]);
    }
    printf("\n\n");
}

void Try(int k){
    for(int v=a[k-1]+1;v<=n-m+k;v++){
        a[k]=v;
        if(k==m){
            Results();
        }else{
            Try(k+1);
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    Try(1);
    return 0;
}