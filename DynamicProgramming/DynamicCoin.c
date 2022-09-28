#include <stdio.h>
#include <time.h>       
#include <stdlib.h>
#include <string.h>
int n,m;
int A[1000000];
int x[1000];
int Min[1000000];
int sum = 0;

void Coins()
{
    for(int i=1; i<=m;i++){
        for(int j=0; j < n;j++){
            if(A[j] <= i && Min[i-A[j]]+1 < Min[i]){
                Min[i] = Min[i-A[j]] + 1;
            }
        }
    }
}

int main()
{
    for(int i=0; i< 1000000;i++){
        Min[i] = 2147483640;
    }
    Min[0] = 0;
    printf("Enter number of coins : ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        //scanf("%d", &A[i]);
        A[i] = rand() % 10;
    }
    printf("Enter total value :  ");
    scanf("%d",&m);

    double time_spent = 0.0;
    clock_t begin = clock();
    
    Coins();
    if(Min[m] == 2147483640)
        printf("%d",-1);
    else
        printf("%d",Min[m]);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nThe elapsed time is %f seconds", time_spent);
    
    return 0;
}