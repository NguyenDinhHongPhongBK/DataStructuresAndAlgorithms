#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[1000000];

int main()
{
    scanf("%s",str);
    int countOne = 0;
    int countZero = 0;
    for(int i=0; i<strlen(str)-1; i++){
        if(str[i] == '1' && str[i+1] == '0')
            countOne ++;   
        if(str[i] == '0' && str[i+1] == '1')
            countZero++;
    }
    if(str[strlen(str)-1] == '1')
        countOne ++;
    if(str[strlen(str)-1] == '0')
        countZero ++;
    printf("%d\n",countZero);
    printf("%d",countOne);
}