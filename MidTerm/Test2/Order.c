#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n;
int Appear[100];
int A[100][100];
int x[40],y[40];
int StartDay[1000], EndDay[1000], Revenue[1000];
int max = 0;

int Check(){
    for(int i = 1;i < n;i++){
        if(x[i] == 1){
            for(int j = i+1;j <= n;j++){
                if(x[j] == 1){
                    if(StartDay[j] >= StartDay[i] && StartDay[j] <= EndDay[i])
                        return 0;
                    if(StartDay[i] >= StartDay[j] && StartDay[i] <= EndDay[j])
                        return 0;
                    if(EndDay[j] >= StartDay[i] && EndDay[j] <= EndDay[i])
                        return 0;
                    if(EndDay[i] >= StartDay[j] && EndDay[i] <= EndDay[j])
                        return 0;
                }
            }
        }
    }
    return 1;
}
void Results(){
    for(int i = 1; i <= n;i++){
        printf("\t%d",x[i]);
    }
    printf("\n");
}

void Try(int k)
{
    for(int v = 1;v <= 2;v++){
        x[k] = v;
        if(k == n){
            int sum = 0;  
            if(Check()){
                for(int i = 1; i <= n ;i++){
                    if(x[i] == 1)
                        sum += Revenue[i];
                }
            } 
            if(sum > max)
                max = sum;
        }
        else{
            Try(k+1);
        }
    }
}


int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&StartDay[i]);
        scanf("%d",&EndDay[i]);
        scanf("%d",&Revenue[i]);
    }
    Try(1);
    printf("%d",max);

}