#include<stdio.h>
#include<stdlib.h>


int appear[100][100],size;
int CoordinateX[8] = {-2,-2,-1,-1,1,1,2,2};
int CoordinateY[8] = {1,-1,2,-2,2,-2,1,-1};
int firstX,firstY;
int count=0,k=0;

void Result(){
    for(int i=1;i<=size;i++){
        for(int j=1;j<=size;j++){
            printf("%d\t",appear[i][j]);
        }
        printf("\n\n");
    }
}


void Knight(int a, int b){
    k++;
    appear[a][b] = k;
    for(int i=0;i<8;i++){
        if(k == size*size){
            Result();
            count++;
            printf("\n\n");
            if(count == 4){
                exit(0);
            }
        }else{
            int u = a + CoordinateX[i];
            int v = b + CoordinateY[i];
            if(u > 0 && u<=size && v > 0 && v<=size && appear[u][v] == 0)
                Knight(u,v);
        }
        
    }
        //Nếu không hợp lệ thì trả về các giá trị cũ
        k--;
        appear[a][b] = 0;
}

int main(){
    printf("Enter size of chessboard : ");
    scanf("%d",&size);
    for(int i=1;i<=size;i++){
        for(int j=1;j<=size;j++){
            appear[i][j] = 0;
        }
    }
    
    printf("Enter first coordinate of Knight : ");
    scanf("%d%d",&firstX,&firstY);
    Knight(firstX,firstY);
}