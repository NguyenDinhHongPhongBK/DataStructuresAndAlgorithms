#include<stdio.h>
#include<stdlib.h>

int n,x[100];
int count;
int A[100][100];
int number;
int PositionX[100];
int PositionY[100];


int Check(int v,int k){
    for(int i=1;i<k;i++){
        if(x[i] == v || x[i] - i == v - k  ||  x[i] + i == v + k)
            return 0;
    }
    for(int j=1;j<=number;j++){
        if(k==PositionX[j] && v!=PositionY[j])
            return 0;
    }
    return 1;
}

void Results(){
    for(int i=1;i<=n;i++){
        printf("%d",x[i]);
    }
    printf("\n");
    for(int k=1;k<=n;k++){
        for(int j=1;j<=n;j++){
            if(j == x[k] ){
                A[k][j] = 1;
            }else{
                A[k][j] = 0;
            }
        }
        
    }
    for(int k=1;k<=n;k++){
        for(int j=1;j<=n;j++){
            printf("%5d",A[k][j]);
        }
        printf("\n\n");
    }
    printf("\n\n\n"); 
    printf("====================\n");
}
void Queen(int k){
    for(int v=1;v<=n;v++){
        if(Check(v,k)){
            x[k] = v;
            if(k==n){
                count++;
                printf("%d)\n",count);
                Results();
            }else{
                Queen(k+1);
            }
        }
    }
}

int main(){
    printf("Enter size of chessboard : ");
    scanf("%d",&n);
    printf("Enter number of Queen in chessboard : ");
    scanf("%d",&number);
    for(int i=1;i<=number;i++){
        printf("Enter  position %d : ",i);
        scanf("%d",&PositionX[i]);
        scanf("%d",&PositionY[i]);
    }
    Queen(1);
    if(count == 0)
        printf("No results");
    else
        printf("There is %d way ",count);
}