#include<stdio.h>
#include<stdlib.h>
#define N 100

int x[N][N];
int A[9][9], number, count = 0;
int satisfyRow[9][10];
int satisfyCol[9][10];
int satisfySquare[3][3][10];


int Test(int v, int p, int q){
    if(satisfyRow[p][v] == 1)
        return 0;
    else if(satisfyCol[q][v] == 1)
        return 0;
    else if(satisfySquare[p/3][q/3][v] == 1)
        return 0;
    if(A[p][q] !=0 && A[p][q] != v)
        return 0;
    return 1;
}

void Sudoku(int p, int q){
    for(int v=1;v<=9;v++){
        if(Test(v,p,q)){
            satisfyRow[p][v] = 1;
            satisfyCol[q][v] = 1;
            satisfySquare[p/3][q/3][v] = 1;
            x[p][q] = v;
            if(p == 8 && q == 8){
                count++;      
            }else{
                if(q == 8){
                    Sudoku(p+1,0);
                }else{
                    Sudoku(p,q+1);
                }
            }
            satisfyRow[p][v] = 0;
            satisfyCol[q][v] = 0;
            satisfySquare[p/3][q/3][v] = 0;
        }
    }
}

int main(){

    for(int v=1;v<=9;v++){
        for(int r=0;r<9;r++){
            satisfyRow[r][v]=0;
        }
        for(int c=0;c<9;c++){
            satisfyCol[c][v]=0;
        }
        for(int i=0;i<=2;i++){
            for(int j=0;j<=2;j++){
                satisfySquare[i][j][v]=0;
            }
        }
    }
    int aaa;
    scanf("%d",&aaa);
   
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                scanf("%d",&A[i][j]);
            }
        Sudoku(0,0);
        printf("%d",count);
        count = 0;
        }


    
}