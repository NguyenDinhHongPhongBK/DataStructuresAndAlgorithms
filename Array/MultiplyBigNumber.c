#include <stdio.h>

int a,b,A[20],B[20];
int X[100][100];
int Units(int a)
{
    return a%10;
}

int Tens(int a)
{
    return a/10;
}

int Numerial(int C[], int x)
{
    int count=1;
    while(x>0){
        C[count] = x%10;
        x/=10;
        count++;
    }
    return count;
}

void MultiplyArray(int A[],int C[], int n, int k, int offset)
{
  int number[20];
  for(int i=0;i<20;i++){
    number[i]=0;
  }
  for(int i=1;i<=n+1+offset;i++){
    if(i<offset)
      number[i] = 0;
    else
      number[i] = A[i-offset+1]*k + Tens(number[i-1]);
    if(i==n+1+offset)
      number[i] = Tens(number[i-1]);
    C[i] = Units(number[i]);
  }
}

void AddArray(int C[], int m, int n)
{
  int number[20];
  for(int i=0;i<20;i++){
    number[i]=0;
    C[i]=0;
  }
  for(int j=1;j<=m+n;j++){
    for(int i=1;i<=n+1;i++){
        number[j] +=  X[i][j];
      }
    number[j] += Tens(number[j-1]);
    C[j] = Units(number[j]);
  }
}
int main()
{
    int C[20];
    // printf("Enter two integer number : ");
    scanf("%d%d",&a,&b);
    int m = Numerial(A,a);
    int n = Numerial(B,b);
    
    for(int i = 1;i <= m;i++){
      for(int j = 1;j <= n+1;j++){
        MultiplyArray(B,X[i],m,A[i],i);
      }
    }
    AddArray(C,m,n);
    
    int D[20];
    for(int i=1;i<=m+n;i++){
      D[i] = C[m+n+1-i];
    }
    int index=1;
    int count=0;
    while(D[index] == 0){
      for(int i=1;i<=m+n;i++){
        D[i] =  D[i+1];
      }
      count++;
    }
    for(int i=1;i<=m+n-count;i++){
      printf("%d",D[i]);
    }
}
