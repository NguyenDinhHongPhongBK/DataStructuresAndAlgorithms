#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int A[1000][1000];
int count = 0;
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i= 0;i< m ;i++){
        for(int j = 0;j< n;j++)
            scanf("%d",&A[i][j]);
    }
    for(int j = 0;j< n;j++){
        int flag = 1;
        for(int i = 0;i< m;i++){
            if(A[i][j] == 0){
                flag = 0;break;
            }
        }
        if(flag == 1)
            count++;
    }
    printf("%d",count);
}