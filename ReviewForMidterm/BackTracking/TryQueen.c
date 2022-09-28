#include<stdio.h>
#include<stdlib.h>

int n,p,x[100];
int count = 0;
int Cx[20],Cy[20];

int Test(int v, int k)
{
    for(int i = 1;i < k;i++){
        if(x[i] == v || x[i] - i == v - k || x[i] + i == v + k)
            return 0;
    }
    for(int j = 1;j <= p;j++){
        if(k == Cx[j] && v != Cy[j]) 
            return 0;
    }
    return 1;
}

int Results()
{
    printf("\t\t");
    for(int i = 1;i <= n;i++){
        printf("\t%d",x[i]);
    }
    printf("\n");
}

void Queen(int k)
{
    for(int v = 1; v <= n; v++){
        if(Test(v,k)){
            x[k] = v;
            if(k == n){
                Results();
                count ++;
            }else{
                Queen(k+1);
            }
        }
    }
}

int main()
{
    printf("\tEnter size of chess board : ");
    scanf("%d",&n);
    do{
        printf("\t\tEnter number of queens : ");
        scanf("%d",&p);
    }while(p>n);
    for(int i=1; i<=p; i++){
        printf("\t\tEnter coordinate of queen %d : ",i+1);
        scanf("%d%d",&Cx[i],&Cy[i]);
    }
    Queen(1);
    printf("%d",count);
}