#include<stdio.h>

int main(){
    int n,A[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    for(int i=0;i<n;i++){
        for(int k=i;k<n;k++){
            for(int j=i;j<=k;j++){
                printf("%4d",A[j]);
            }
            printf("\n\n");
        }
        printf("\n\n");
    }
}