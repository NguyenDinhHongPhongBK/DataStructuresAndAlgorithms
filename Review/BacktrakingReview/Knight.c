#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int x[100][100],a[100],count=0,appear[100][100];
int firstX, firstY;

int Distance(int a,int b,int c,int d){
    return pow(c-a,2) + pow(b-d,2);
}

int Test(int v,int k){
    if(appear[v/8][v%8] == 1)
        return 0;
    if(v/8==firstX && v%8==firstY && k!=1)
        return 0;
    if(k>1){
        if(Distance(v/8, v%8, a[k-1]/8, a[k-1]%8) != 5)
            return 0;
    }
    return 1;
}

void Results(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            printf("%d\t",x[i][j]);
        }
        printf("\n\n");
    }
}

void Knight(int k){
    for(int v=0;v<64;v++){
        if(Test(v,k)){
            a[k] = v;
            x[v/8][v%8] = k;
            appear[v/8][v%8] = 1;     
            if(k==64){
                Results();
                printf("\n\n\n");
                count++;
                if(count == 2)
                    exit(0);
            }else{
                Knight(k+1);
            }
            appear[v/8][v%8] = 0;
        }
    }
}

int main(){
    printf("Enter first position of Knight : ");
    scanf("%d%d",&firstX,&firstY);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            appear[i][j] = 0;
        }
    }
    Knight(1);
    if(count == 0){
        printf("No results found");
    }
}