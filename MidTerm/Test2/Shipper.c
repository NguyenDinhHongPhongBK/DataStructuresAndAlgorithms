#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n,m;
int Position[1001];
int A[1001][1001];
int x[1001];
int First[1000001],Second[1000001];


int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&Position[i]);
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            scanf("%d",&A[i][j]);
        }
    }

    int flag = 0;
    int preFlag = 1;
    scanf("%d",&m);
    for(int i = 1;i<=m;i++){
        flag = 0;
        scanf("%d",&First[i]);
        scanf("%d",&Second[i]);
        if(preFlag == 1){
            int p = 0,q = 0;
            for(int j = 1;j<=n;j++){
                if(First[i] == Position[j])
                    p = j;
                if(Second[i] == Position[j])
                    q = j;
            }
            if(p < q && q != 0 && p != 0)
                flag = 1;
            else
                preFlag = 0;
        }
    }

    if(flag == 1){
        int sum = 0;
        for(int i = 1;i <= n;i++){
            if(i == n){
                sum += A[Position[i]][Position[1]];
            }
            else{
                sum+= A[Position[i]][Position[i+1]];
            }
        }
        printf("%d",sum);
    }
    else
        printf("%d",-1);
}