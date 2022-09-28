#include<stdio.h>
#include<time.h>
unsigned long long int Combination(int k,int n){
    if(k==0 || k==n){
        return 1;
    }
    else{
        return Combination(k-1,n-1) + Combination(k,n-1);
    }
}

int main(){
    
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    int k,n;
    printf("Enter two integer (k<n) : ");
    scanf("%d%d",&k,&n);
    printf("%llu",Combination(k,n));

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nThe elapsed time is %f seconds", cpu_time_used);
    return 0;
}