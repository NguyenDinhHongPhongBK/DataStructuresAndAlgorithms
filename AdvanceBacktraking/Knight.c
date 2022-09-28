#include<stdio.h>
#include<stdlib.h>

int size, x[100],y[100];
int appear[100][100];
int A[8] ={1,1,2,2,-1,-1,-2,-2};
int B[8] ={2,-2,1,-1,2,-2,1,-1};
int BeginX, BeginY;
int count = 0;

int Test(int v,int k)
{
    if(appear[x[k-1] + A[v]][y[k-1] + B[v]] == 1)
        return 0;
    if((x[k-1] + A[v]) <= 0 || (x[k-1] + A[v]) > size || (y[k-1] + B[v]) <= 0 || (y[k-1] + B[v]) > size)
        return 0;
    return 1;
}

void Results()
{
    for(int i = 1;i <= size;i++){
        for(int j = 1;j <= size;j++){
            for(int s = 0;s< size*size;s++){
                if(x[s] == i && y[s] == j)
                    printf("\t%d",s+1);
            }
        }
        printf("\n\n");
    }
    printf("\n\n");
}

void Knight(int k)
{
    for(int v = 0; v < 8 ;v++){
        if(Test(v,k)){
            x[k] = x[k-1] + A[v];
            y[k] = y[k-1] + B[v];
            appear[x[k]][y[k]] = 1;
            if(k == size*size - 1){
                printf("\n\t\t\tWay %d\n\n", count+1);
                Results();
                count++;
                if(count == 2000)
                    exit(0);
            }else{
                Knight(k+1);
            }
            appear[x[k]][y[k]] = 0;
        }
    }
}

int main()
{
    for(int i = 0;i < 100;i++)
        for(int j = 0; j <100;j++)
            appear[i][j] = 0;

    printf("\tEnter size of chess board : ");
    scanf("%d",&size);
    printf("\t\tEnter beginning position  : ");
    scanf("%d%d",&BeginX,&BeginY);
    x[0] = BeginX;
    y[0] = BeginY;
    appear[x[0]][y[0]] = 1;
    Knight(1);
}