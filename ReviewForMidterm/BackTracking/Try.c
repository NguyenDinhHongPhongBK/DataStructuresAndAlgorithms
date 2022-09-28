#include<stdio.h>
#include<stdlib.h>

int n;
int x[100];
int appear[100];

int Test(int v)
{
    if(appear[v] == 1)
        return 0;
    return 1;
}

void Results()
{
    for(int i = 1;i <= n;i++){
        printf("%d",x[i]);
    }
    printf("\n");
}

void Try(int k)
{
    for(int v = 1;v <= n;v++){
        if(Test(v)){
            x[k] = v;
            appear[v] = 1;
            if(k == n){
                Results();
            }else{
                Try(k+1);
            }
            appear[v] = 0;
        }
    }
}

int main()
{
    printf("Enter number : ");
    scanf("%d", &n);
    for(int i = 0;i <= 100;i++){
        appear[i] = 0;
    }
    Try(1);
}