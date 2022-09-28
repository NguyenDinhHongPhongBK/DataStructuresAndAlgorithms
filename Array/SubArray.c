#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
#define  MAXSUM INT_MIN


int main(){
    double time_spent = 0.0;
    clock_t begin = clock();
    // Content
   
    int n,A[100000];
    printf("Enter number of terms in array : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        A[i]=rand();
        printf("%7d",A[i]);
    } 
    int MaxSum=A[0],e=A[0];
    for(int i=0;i<n-1;i++){
        if(e+A[i]>A[i])
            e=e+A[i];
        else e=A[i];
        if(e>MaxSum){
            MaxSum=e;
        }
    }
    printf("\nMax : %d",MaxSum);
    //
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nThe elapsed time is %f seconds", time_spent);
    return 0;
}
