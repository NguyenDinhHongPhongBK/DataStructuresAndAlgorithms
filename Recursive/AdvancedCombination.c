#include<stdio.h>
#include <time.h>       
#include <unistd.h>     

#define P 1000000007
#define N 1000

unsigned long long int M[N][N];
void Initialization(){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            M[i][j]=0;
}
unsigned long long int Combination(int k,int n){
    if(k==0 || k==n){
        M[k][n]=1;
    }
    else{
        if(M[k][n]==0){
            M[k][n]=(Combination(k-1,n-1)+Combination(k,n-1));
        }
    }
    return M[k][n];
}
int main()
{
    // to store the execution time of code
    clock_t start, end;
    double cpu_time_used;
    start = clock();


    Initialization();
    int k,n;
    int M[20];
    M[1];
    scanf("%d%d",&k,&n);
    printf("%llu",Combination(k,n));

    
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nThe elapsed time is %f seconds", cpu_time_used);
    return 0;
}

