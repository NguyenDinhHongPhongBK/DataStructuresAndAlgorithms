#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int x[100];
int n;
int appear[100];
int count = 0;

int check(int v, int k){
    if(appear[v] == 1)
        return 0;
    if(k<6)
        return 1;
    else{
        if((x[0]*100 + x[1]*10 + x[2] - x[3]*100 - 62 + x[4]*1000 + x[5]*100 + v*10 + x[2]) == n)
            return 1;
        else
            return 0;
    }
}

void Try(int k){
    for(int v=1;v<=9;v++){
        if(check(v,k)){
            x[k] = v;
            appear[v] = 1;
            if(k==6)
                count++;
            else{
                Try(k+1);
            }
                appear[v] = 0;
        }
    }
}

int main()
{
    for(int i=0;i<100;i++){
        appear[i] = 0;
    }
    scanf("%d",&n);
    Try(0);
    printf("%d",count);
}
