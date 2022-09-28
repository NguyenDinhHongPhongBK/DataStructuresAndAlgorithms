#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct Node{
    char fromNumber[20];
    int nbCalls;
    int durations;
    struct Node* leftChild;
    struct Node* rightChild;
}Node;

Node *root;

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

Node *MakeNode(char *fromNumber,int nbCalls,int durations)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->fromNumber,fromNumber);
    newNode->nbCalls = nbCalls;
    newNode->durations = durations;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

Node *InsertNode(char *fromNumber,int nbCalls,int durations,Node *r)
{
    if(r == NULL)
        r = MakeNode(fromNumber,nbCalls,durations);
    int c = strcmp(r->fromNumber,fromNumber);
    if(c == 0)
        return r;
    if(c > 0)
        r->leftChild = InsertNode(fromNumber,nbCalls,durations,r->leftChild);
    else
        r->rightChild = InsertNode(fromNumber,nbCalls,durations,r->rightChild);
    return r;
}

Node *Find(char *fromNumber,Node *r){
    if(r == NULL) return NULL;
    int c = strcmp(r->fromNumber,fromNumber);
    if(c == 0) return r;
    if(c < 0)
        return Find(fromNumber,r->rightChild);
    else
        return Find(fromNumber,r->leftChild);
}



int main()
{
    char call[5];
    char callFrom[11];
    char callTo[11];
    char date[11];
    char timeFrom[9];
    char timeTo[9];
    int flag = 1;
    int number = 0;
    while(1){
        scanf("%s",&call);
        if(strcmp(call,"#") == 0)
            break;
        scanf("%s",&callFrom);
        if(CheckPhoneNumber(callFrom) == 0)
            flag = 0;
        scanf("%s",&callTo);
        if(CheckPhoneNumber(callTo) == 0)
            flag = 0;
        scanf("%s",&date);
        scanf("%s",&timeFrom);
        scanf("%s",&timeTo);
        number++;
        Node *p = Find(callFrom,root);
        int duration = CountTime(timeFrom,timeTo);
        if(p == NULL)
            root = InsertNode(callFrom,1,duration,root);
        else{
            p->nbCalls +=1;
            p->durations +=duration;
        }
    }
    char cmd[100];
    do{
        scanf("%s",&cmd);
        int flag = 1;
        if(strcmp(cmd,"?check_phone_number") == 0){
            if(flag == 0)
                printf("%d\n",0);
            else 
                printf("%d\n",1);
        }
        if(strcmp(cmd,"?number_calls_from") == 0){
            char callNumber[100];
            scanf("%s",callNumber);
            Node *p = Find(callNumber,root);
            if(p == NULL)
                printf("%d\n",0);
            else
                printf("%d\n",p->nbCalls);
        }
        if(strcmp(cmd,"?number_total_calls") == 0){
            printf("%d\n",number);
        }
        if(strcmp(cmd,"?count_time_calls_from") == 0){
            char callNumber[100];
            scanf("%s",callNumber);
            Node *p = Find(callNumber,root);
            if(p == NULL)
                printf("%d\n",0);
            else
                printf("%d\n",p->durations);
        }
        
    }while(strcmp(cmd,"#") != 0);
}