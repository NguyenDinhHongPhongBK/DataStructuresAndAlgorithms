#include <stdio.h>

int max=-1;
void SubArray(int n, int m, int A[][100]){
    for(int i1=0;i1<n;i1++){
        for(int j1=0;j1<m;j1++){
            for(int i2=i1;i2<n;i2++){
                for(int j2=j1;j2<m;j2++){
                    int sum=0;
                    for(int i3=i1;i3<=i2;i3++){
                        for(int j3=j1;j3<=j2;j3++){
                            printf("%3d",A[i3][j3]);
                            if(A[i3][j3] == 0) break;
                            sum+=A[i3][j3];
                        }
                        printf("\n");
                    }    
                    if(sum>max)
                        max=sum;
                    printf("\n\n");
                } 
            }
        }
    }
}

int main(){
    int n,m,A[100][100];
    printf("Enter rows : ");
    scanf("%d",&n);
    printf("Enter columns :");
    scanf("%d",&m);

    for(int i=0;i<n;i++){
        for(int j=0; j<m;j++){
            scanf("%d",&A[i][j]);
        }
    }
    printf("\n\n");
    for(int i=0;i<n;i++){
        for(int j=0; j<m;j++){
            printf("%d\t",A[i][j]);
        }
        printf("\n\n");
    }
    SubArray(n,m,A);
    printf("%d",max);
;}