#include <stdio.h>

int n;

void Print(int k, int A[]){
    if(k==0){
        return;
    }
    Print(k-1,A);
    printf("%d\t",A[k]);
}

int main(){
    int A[20];
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    Print(n,A);
}