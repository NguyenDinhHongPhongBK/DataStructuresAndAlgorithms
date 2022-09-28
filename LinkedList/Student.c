#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256

typedef struct Profile{
    char name[MAX];
    char email[MAX];
    struct Profile *next;
}Profile;

Profile *first, *last;

Profile *CreateProfile(char *name, char *email)
{
    Profile *p = (Profile *)malloc(sizeof(Profile));
    strcpy(p->name, name);
    strcpy(p->email, email);
    p->next = NULL;
    return p;
}

void CreateInitialProfile()
{
    first = NULL;
    last = NULL;
}

int CheckEmptyProfile()
{
    return first == NULL && last == NULL;
}

void InsertLast(char *name, char *email)
{
    Profile *p = CreateProfile(name, email);
    if(CheckEmptyProfile()){
        first = p;
        last = p;
    }else{
        last->next = p;
        last = p;
    }
}

Profile *RemoveProfile(Profile *p, char *name)
{
    if(CheckEmptyProfile()) return NULL;
    if(strcmp(p->name,name) ==0){
        Profile *tmp = p->next;
        free(p);
        if(tmp == NULL)
            last = NULL;
        return tmp;
    }else{
        p->next = RemoveProfile(p->next,name);
        return p;
    }
}

void FindProfile(char *name)
{
    int flag = 0;
    for(Profile *cur = first; cur != NULL; cur = cur->next){
        if(strcmp(cur->name,name) == 0){
            printf("\t\t Name : %s, Email : %s\n",cur->name,cur->email);
            flag++;
        }
    }
    if(flag == 0){
        printf("\tThere is no student name %s in this list.",name);
    }
}

void Show()
{
    printf("\n\t\t+------------------------------+------------------------------+");
    printf("\n\t\t|               Name           |            Email             |");
    printf("\n\t\t+------------------------------+------------------------------+");
    for(Profile *cur = first; cur != NULL; cur = cur->next){
        printf("\n\t\t|%30s|%30s|",cur->name,cur->email);
        printf("\n\t\t+------------------------------+------------------------------+");
    }
    printf("\n\n");
}

int main()
{
    char cmd[20];
    do{
        printf("Enter command : ");
        scanf("%s", &cmd);
        if(strcmp(cmd, "Add") == 0){
            char name[MAX];
            char email[MAX];
            printf("\tEnter name : ");
            fflush(stdin);
            gets(name);
            printf("\tEnter email : ");
            scanf("%s",&email);
            InsertLast(name, email);
        }
        if(strcmp(cmd,"Show") == 0){
            Show();
        }
        if(strcmp(cmd,"Remove") == 0){
            char move[MAX];
            printf("\tEnter name to remove : ");
            fflush(stdin);
            gets(move);
            first = RemoveProfile(first,move);
        }
        if(strcmp(cmd,"Find") == 0){
            char find[MAX];
            printf("\tEnter name to find : ");
            fflush(stdin);
            gets(find);
            FindProfile(find);
        }
    }while(strcmp(cmd,"Exit") != 0);
}
