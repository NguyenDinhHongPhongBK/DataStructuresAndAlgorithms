#include <stdio.h>
int n,money[100],x[100];
int count=0, sum;



int Test(int v, int k){
    return 1;
}

void Results(){
    for(int i=1;i<=n;i++){
        if(x[i] == 1){
            printf("\tB");
        }else{
            printf("\tA");
        }
    }
    printf("\n\n");
}

void SplitMoney(int k){
    for(int v=0;v<=1;v++){
        if(Test(v,k)){
            x[k]=v;
            if(n==k){
                int total=0;
                for(int i=1;i<=n;i++){
                    if(x[i]==1){
                        total+=money[i];
                    }
                }
                if(total == 0.5*sum){
                    Results();
                    count++;
                }
                    
            }else{
               SplitMoney(k+1);
            }
        }
    }
}

int main(){
    printf("Enter number of banknotes : ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("Enter nomial value of banknote %d : ",i);
        scanf("%d",&money[i]);
    }
    sum=0;
    for(int i=1;i<=n;i++){
        sum+=money[i];
    }
    if(sum%2==1)
        printf("No result");
    else{
        for(int i=1;i<=n;i++){
            printf("\t%d",money[i]);
        }
        printf("\n\n");
        SplitMoney(1);
        if(count==0)
            printf("No result");
        else
            printf("\n\t\tThere are %d results\n\n",count);
    }
   
}