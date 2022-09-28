#include <stdio.h>
int n,A[100];

int Check(int A[], int n){
    int count[100];
    count[0] = 0;
    int max=0;
    int index=0;
    for(int i=0;i<n;i++){
        if(A[i+1] > A[i]){
            count[index]++;
        }else{
            if(count[index] > max){
                max=count[index];
            }
            index++;
            count[index] = 0;
        }
    }
    return max;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    A[n] = 0;
    printf("%d",Check(A,n));
}