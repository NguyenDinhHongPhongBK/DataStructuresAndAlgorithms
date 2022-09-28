#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Number{
    int number;
    struct Number* next;
}Number;

Number *head;

void CreateInitial()
{
    head = NULL;
}

int Empty()
{
    return head == NULL;
}

int CheckAppear(int p)
{
    int flag = 0;
    for(Number *cur = head;cur != NULL;cur = cur->next){
        if(cur->number == p){
            flag = 1;break;
        }
    }
    return flag;
}

Number *CreateNumber(int X)
{
    Number *p = (Number*) malloc(sizeof(Number));
    p->number = X;
    p->next = NULL;
    return p;
}

void AddLast(int p)
{
    if(CheckAppear(p))
        printf("\t\t\t%d has appeared in the list\n",p);
    else{
        Number *f = CreateNumber(p);
        if(Empty()){
            head = f;
        }else{
            Number *cur = head;
            while(cur->next != NULL) cur = cur->next;
            cur->next = f;
        }
    }
}

void Addfirst(int p)
{
    if(CheckAppear(p))
        printf("\t\t\t%d has appeared in the list\n",p);
    else{
        Number *f = CreateNumber(p);
        if(Empty()){
            head = f;
        }else{
            f->next = head;
            head = f;
        }
    }
}

void AddAfter(int p, int q)
{
    if(!CheckAppear(p))
        printf("\t\t\t%d has not appeared in this list\n",p);
    if(CheckAppear(q))
        printf("\t\t\t%d has appeared in this list\n",q);
    if(CheckAppear(p) && !CheckAppear(q)){
        Number *cur = head;
        Number *c = CreateNumber(q);
        while(cur->number != p) cur = cur->next;
        if(cur->next == NULL)
            cur->next = c;
        else{
            c->next = cur->next;
            cur->next = c;
        }
    }
}

void AddBefore(int p, int q)
{
    if(!CheckAppear(p))
        printf("\t\t\t%d has not appeared in this list\n",p);
    if(CheckAppear(q))
        printf("\t\t\t%d has appeared in this list\n",q);
    if(CheckAppear(p) && !CheckAppear(q)){
        Number *cur = head;
        Number *c = CreateNumber(q);
        if(head->number == p){
            c->next = head;
            head = c;
        }
        else{
            while(cur->next->number != p) cur = cur->next;
            c->next = cur->next;
            cur->next = c;
        }
    }
}

void Remove(int p){
    if(!CheckAppear(p))
        printf("\t\t\t%d has not appeared in this list\n",p);
    else{
        if(!Empty()){
            Number *cur = head;
            Number *prev = NULL;
            while(cur->number != p){
                prev = cur;
                cur = cur->next;
            }
            if(cur == head){
                head = cur->next;
                free(cur);
            }
            else{
                prev->next = cur->next;
                free(cur);
            }
        }
    }
}

void Reverse()
{
    Number *cur = head;
    Number *prev = NULL;
    Number* after;
    while(cur != NULL){
        after = cur->next;
        cur->next = prev;
        prev = cur;
        cur = after;
    }
    head = prev;
}

void Show()
{
    printf("\t\t");
    for(Number *cur = head; cur != NULL; cur = cur->next){
        printf("\t%d", cur->number);
    }
    printf("\n");
}

int main()
{
    char cmd[100];
    int n;
    do{
        printf("\tEnter command : ");
        scanf("%s", &cmd);
        if(strcmp(cmd, "al") == 0){
            printf("\t\tEnter number to add last : ");
            scanf("%d", &n);
            AddLast(n);
            Show();
        }
        if(strcmp(cmd, "af") == 0){
            printf("\t\tEnter number to add first : ");
            scanf("%d", &n);
            Addfirst(n);
            Show();
        }
        if(strcmp(cmd,"aa") == 0){
            printf("\t\tEnter number to add after it : ");
            scanf("%d", &n);
            int a;
            printf("\t\tEnter number to add after : ");
            scanf("%d",&a);
            AddAfter(n,a);
            Show();
        }
        if(strcmp(cmd,"ab") == 0){
            printf("\t\tEnter number to add before it : ");
            scanf("%d", &n);
            int a;
            printf("\t\tEnter number to add before : ");
            scanf("%d",&a);
            AddBefore(n,a);
            Show();
        }
        if(strcmp(cmd,"rm") == 0){
            printf("\t\tEnter number to remove : ");
            scanf("%d", &n);  
            Remove(n);
            Show();
        }
        if(strcmp(cmd,"rv") == 0){
            Reverse();
            Show();
        }
    }while(strcmp(cmd,"exit") != 0);
}