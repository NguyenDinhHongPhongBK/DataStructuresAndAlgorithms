#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define M  100007

int Hash(char *s)
{
    int c = 0;
    for(int i = 0 ; i< strlen(s); i ++){
        c = (c*256 + s[i]) % M;
    }
    return c;
}

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

typedef struct Tree{
    char fromNumber[20];
    int nbCalls;
    int durations;
    struct Tree *left;
    struct Tree *right;
}Tree;

Tree *ArrRoot[M];

Tree* CreateNode(char *phoneNumber,int nbCalls,int durations)
{
    Tree *n = (Tree*) malloc(sizeof(Tree));
    strcpy(n->fromNumber,phoneNumber);
    n->nbCalls = nbCalls;
    n->durations = durations;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Tree* InsertToTree(Tree *root, char *phoneNumber,int call, int durations)
{
    if(root == NULL) 
        root = CreateNode(phoneNumber,call,durations);
    int a = strcmp(root->fromNumber,phoneNumber);
    if(a == 0)
        return root;
    if(a > 0)
        root->left = InsertToTree(root->left,phoneNumber,call,durations);
    else
        root->right = InsertToTree(root->right,phoneNumber,call,durations);
    return root;
}

Tree *FindFromTree(char *fromNumber,Tree *root){
    if(root == NULL) return NULL;
    int c = strcmp(root->fromNumber,fromNumber);
    if(c == 0) return root;
    if(c < 0)
        return FindFromTree(fromNumber,root->right);
    else
        return FindFromTree(fromNumber,root->left);

}

Tree*FIND(char *phoneNumber)
{
    int hash = Hash(phoneNumber);
    if(ArrRoot[hash] == NULL) return NULL;
    Tree *f = FindFromTree(phoneNumber,ArrRoot[hash]);
    return f;
}

// void INSERT(char *phoneNumber,int call,int durations)
// {
//     Tree *n = FIND(phoneNumber);
//     int hash = Hash(phoneNumber);
//     if(n == NULL)
//         ArrRoot[hash] = InsertNode(phoneNumber,call,durations,ArrRoot[hash]);
    
// }

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
        int hash = Hash(callFrom);
        Tree *f = FIND(callFrom);
        int duration = CountTime(timeFrom,timeTo);
        if(f == NULL)
            ArrRoot[hash] = InsertToTree(ArrRoot[hash],callFrom,1,duration);
        else{
            f->nbCalls +=1;
            f->durations +=duration;
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
            Tree *p = FIND(callNumber);
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
            Tree *p = FIND(callNumber);
            if(p == NULL)
                printf("%d\n",0);
            else
                printf("%d\n",p->durations);
        }
        
    }while(strcmp(cmd,"#") != 0);
}