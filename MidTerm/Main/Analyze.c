#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int getMonth(char date[])
{
    char b[3];
    memset(b, '\0', sizeof(b));
    strncpy(b,date+5,2);
    if(strcmp(b,"01") == 0)
        return 1;
    else if(strcmp(b,"02") == 0)
        return 2;
    else if(strcmp(b,"03") == 0)
        return 3;
    else if(strcmp(b,"03") == 0)
        return 3;
    else if(strcmp(b,"04") == 0)
        return 4;
    else if(strcmp(b,"05") == 0)
        return 5;
    else if(strcmp(b,"06") == 0)
        return 6;
    else if(strcmp(b,"07") == 0)
        return 7;
    else if(strcmp(b,"08") == 0)
        return 8;
    else if(strcmp(b,"09") == 0)
        return 9;
    else if(strcmp(b,"10") == 0)
        return 10;
    else if(strcmp(b,"11") == 0)
        return 11;
    else if(strcmp(b,"12") == 0)
        return 12;
    else
        return 0;
}

int main()
{
    char Date[10][1000];
    int i = 0;
    int Month[1000];
    do{
        //printf("Enter date : ");
        scanf("%s",&Date[i]);
        if(strcmp(Date[i],"#") != 0){
            Month[i] = getMonth(Date[i]);
            i++;
        }
    }while(strcmp(Date[i],"#") != 0 );
    // int M[12]={1,2,3,4,5,6,7,8,9,10,11,12};
    int Index[12];
    for(int i = 0; i < 12; i++)
        Index[i] = 0;
    for(int j = 0;j < i;j++){
        if(Month[j] == 1)
            Index[0] ++;
        else if(Month[j] == 2)
            Index[1] ++;
        else if(Month[j] == 3)
            Index[2] ++;
        else if(Month[j] == 4)
            Index[3] ++;
        else if(Month[j] == 5)
            Index[4] ++;
        else if(Month[j] == 6)
            Index[5] ++;
        else if(Month[j] == 7)
            Index[6] ++;
        else if(Month[j] == 8)
            Index[7] ++;
        else if(Month[j] == 9)
            Index[8] ++;
        else if(Month[j] == 10)
            Index[9] ++;
        else if(Month[j] == 11)
            Index[10] ++;
        else if(Month[j] == 12)
            Index[11] ++;
    }
    int max = Index[0];
    for(int k = 1;k<12;k++){
        if(Index[k] > max) 
            max = Index[k];
    }
    printf("%d",max);
    
}