#include<stdio.h>
int Units(int a)
{
    return a%10;
}
int Tens(int a)
{
    return a/10;
}
int main()
{
    int A[20],n,B[20],k,number[20];
    for(int i=1;i<=20;i++){
        number[i] = 0;
    }
    printf("Enter number of elements in this array : ");
    scanf("%d",&n);
    printf("Enter value of each element : ");
    for(int i=1;i<=n;i++){
        scanf("%d",&A[i]); 
    }
    printf("\t");
    for(int i=1;i<=n;i++){
        printf("%d\t",A[i]);
    }
    A[0] = 0;
    printf("\tEnter factor to multiply : ");
    scanf("%d",&k);
    for(int i=n+1;i>=1;i--){
        number[i] = A[i-1]*k + Tens(number[i+1]);
        B[i] = Units(number[i]);
    }
    for(int i=1;i<=n+1;i++){
        printf("%d\t",B[i]);
    }


}