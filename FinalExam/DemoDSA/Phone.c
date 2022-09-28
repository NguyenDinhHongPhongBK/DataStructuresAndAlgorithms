#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define size 1000
typedef struct Time{
    int hour;
    int minute;
    int second;
}Time;

int CheckPhoneNumber(char *number)
{
    if(strlen(number) != 10)
        return 0;
    for(int i = 0; i < 10; i++){
        if(!isdigit(number[i]))
            return 0;
    }
    return 1;
}

int CheckDate(char *date)
{
    if(strlen(date) != 10)
        return 0;
    for(int i = 0; i < 10; i++){
        if(i != 4 && i != 7){
            if(!isdigit(date[i]))
                return 0;
        }
        else{
            if(date[i] != '-')
                return 0;
        }
    }
    return 1;
}

int CheckTime(char *time)
{
    if(strlen(time) != 8)
        return 0;
    for(int i = 0; i < 10; i++){
        if(i != 2 && i != 5){
            if(!isdigit(time[i]))
                return 0;
        }
        else{
            if(time[i] != ':')
                return 0;
        }
    }
    return 1;
}

int GetHours(char * date){
    int i = date[0] - '0';
    int j = date[1] - '0';
    return i*10 +j;
}

int GetMinute(char * date){
    int i = date[3] - '0';
    int j = date[4] - '0';
    return i*10 +j;
}

int GetSecond(char * date){
    int i = date[6] - '0';
    int j = date[7] - '0';
    return i*10 +j;
}

int CountTime(char * date1, char* date2){
    int hour1 = GetHours(date1);
    int minute1 = GetMinute(date1);
    int second1 = GetSecond(date1);
    int hour2 = GetHours(date2);
    int minute2 = GetMinute(date2);
    int second2 = GetSecond(date2);
    int time;
    if(hour1 == hour2){
        time = (minute2 - minute1)*60 - (second1 - second2);
    }
    else{
        time = (hour2 - hour1 -1)*3600 + (60 - minute1 - 1)*60 + 60 - second1 + minute2*60 + second2;
    }
    return time;
}

int main()
{
    char call[5][size];
    char callFrom[11][size];
    char callTo[11][size];
    char date[11][size];
    char timeFrom[9][size];
    char timeTo[9][size];
    int number = 0;
    while(1){
        scanf("%s",&call[number]);
        if(strcmp(call[number],"#") == 0)
            break;
        scanf("%s",&callFrom[number]);
        scanf("%s",&callTo[number]);
        scanf("%s",&date[number]);
        scanf("%s",&timeFrom[number]);
        scanf("%s",&timeTo[number]);
        number++;
    }
    char cmd[size];
    do{
        scanf("%s",&cmd);
        int flag = 1;
        if(strcmp(cmd,"?check_phone_number") == 0){
            for(int i = 0;i < number;i++){
                if(CheckPhoneNumber(callFrom[i]) == 0 || CheckPhoneNumber(callTo[i]) == 0)
                    flag = 0;break;
            }
            printf("%d\n",flag);
        }
        if(strcmp(cmd,"?number_calls_from") == 0){
            char phoneNumber[11];
            scanf("%s",&phoneNumber);
            int count = 0;
            for(int i = 0;i < number;i++){
                if(strcmp(phoneNumber,callFrom[i]) == 0)
                    count++;
            }
            printf("%d\n",count);
        }
        if(strcmp(cmd,"?number_total_calls") == 0){
            printf("%d\n",number);
        }
        if(strcmp(cmd,"?count_time_calls_from") == 0){
            char phoneNumber[11];
            scanf("%s",&phoneNumber);
            int time = 0;
            for(int i = 0;i < number;i++){
                if(strcmp(callFrom[i],phoneNumber) == 0)
                    time += CountTime(timeFrom[i],timeTo[i]);
            }
            printf("%d\n",time);
        }
        
    }while(strcmp(cmd,"#") != 0);

}