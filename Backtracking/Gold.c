#include<stdio.h>
#include<stdlib.h>


int n,L1,L2;
int x[100000],A[100000];
int sum = 0;
int max = 0;

int check(int v, int k){
    
}


void Try(int k)
{
    int v;
    for(v=0;v<=1;v++){
        if(check(v,k)){
            x[k]=v;
            if(k==n){
                int index = -1;
                int flag = 1;
                for(int i=1;i<=n;i++){
                    if(x[i] == 0){
                        index = i;break;
                    }
                }
                int m = index;
                if(index != -1){
                    if(index == n){
                        int sum = A[n];
                        if(sum > max) max = sum;
                    }
                    else{
                        for(int i = index + 1;i<=n;i++){
                            if(x[i] == 0){
                                if((i - index) < L1 || (i - index) > L2){
                                    flag = 0;break;
                                }
                                index = i;
                            }
                        }
                        if(index == m){
                            int sum = A[index];
                            if(sum > max) max = sum;
                        }
                        else{
                            if(flag == 1){
                                int sum = 0;
                                for(int i = 1;i<=n;i++){
                                    if(x[i] == 0){
                                        sum += A[i];
                                    }
                                }
                                if(sum > max) max = sum;
                            }
                        }
                    }
                }
            }
            else{
                Try(k+1);
            }
        }
    }
}

int main(){
    scanf("%d",&n);
    scanf("%d%d",&L1,&L2);
    for(int i=1;i<=n;i++)
        scanf("%d",&A[i]);
    Try(1);
    printf("%d",max);
}