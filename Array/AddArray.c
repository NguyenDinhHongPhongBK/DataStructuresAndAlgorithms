
#include<stdio.h>

int Units(int a)
{
    return a%10;
}
int Tens(int a)
{
    return a/10;
}

void SumArray(int A[][30],int n, int m)
{
    for(int i=1;i<=m;i++){
        A[i][0] = 0;
    }
    int number[30],B[30];
    for(int i=1;i<=30;i++){
        number[i] = 0;
    }
    for(int j=m+1;j>=1;j--){
        for(int i=1;i<=n;i++){
            number[j] +=  A[i][j-1];
        }
        number[j] += Tens(number[j+1]);
        B[j] = Units(number[j]);
    }
    for(int i=1;i<=m+1;i++){
        printf("%d\t",B[i]);
    }
}

int main()
{
    int A[30][30],n,m;
    printf("Enter number of rows and columns : ");
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&A[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
    SumArray(A,n,m);
    
}