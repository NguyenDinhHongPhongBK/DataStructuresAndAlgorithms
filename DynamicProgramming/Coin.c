#include <stdio.h>
#include <time.h>       
#include <stdlib.h>
#include <string.h>
int n,m;
int A[1000000];
int x[1000];
int min ;
int sum = 0;
int count = 0;

int FindMax(int n)
{
    int max = 0;
    int index;
    for(int i = 0; i < n; i++){
        if(A[i] > max){
            max = A[i];
            index = i;
        }
    }
    return index;
}


int main()
{
    printf("Enter number of coins : ");
    scanf("%d", &n);
    for(int i = 0; i <n; i++){
        A[i] = rand() % 10;
        //scanf("%d", &A[i]);
    }
    printf("Enter total value :  ");
    scanf("%d",&m);

    double time_spent = 0.0;
    clock_t begin = clock();
    
    while(1){
        if(m == 0 || n == 0) break;
        int intdexMax = FindMax(n);
        int max = A[intdexMax];
        int number = m/max;
        count+=number;
        m -= number*max;
        for(int i = intdexMax;i < n-1;i++){
            A[i] = A[i+1];
        }
        n--;
    }

    if(m == 0)
        printf("%d",count);
    else
        printf("%d",-1);
    
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nThe elapsed time is %f seconds", time_spent);
    
    return 0;
}