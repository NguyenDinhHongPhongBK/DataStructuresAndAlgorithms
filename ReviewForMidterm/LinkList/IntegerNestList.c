#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Number{
    int number;
    struct Number *next;
}Number;

typedef struct Series{
    int id;
    Number *numbers;
    struct Series *next;
}Series;

Series *head,*tail;

int EmptySeries()
{
    return head == NULL && tail == NULL;
}

Series *CreateSeries(int id)
{
    Series *s = (Series *)malloc(sizeof(Series));
    s->id = id;
    s->numbers = NULL;
    s->next = NULL;
    return s;
}

void CREATE(int id)  //Add to last
{
    Series *s = CreateSeries(id);
    if(EmptySeries()){
        head = s;tail = s;
    }else{
        tail->next = s;
        tail = s;
    }
}

Number *CreateNumber(int number)
{
    Number *n = (Number *)malloc(sizeof(Number));
    n->number = number;
    n->next = NULL;
    return n;
}

Number *Addlast(Number* head, int number){
    Number *p = CreateNumber(number);
    if(head == NULL){
        head = p;
    }else{
        Number *last = head;
        while(last->next != NULL) 
            last = last->next;
        last->next = p;
    }
    return head;
}

void ADDTERM(int id, int number)
{
    for(Series *cur = head; cur != NULL; cur = cur->next){
        if(cur->id == id){
            cur->numbers = Addlast(cur->numbers,number);
        }
    }
}


int main()
{
    char cmd[20];
    int id, n;
    do{
        printf("\tEnter command : ");
        scanf("%s",&cmd);
        if(strcmp(cmd,"c") == 0){
            printf("\t\tEnter id to create : ");
            scanf("%d",&id);
            CREATE(id);
        }
        if(strcmp(cmd,"a") == 0){
            printf("\t\tEnter id to add : ");
            scanf("%d",&id);
            printf("\t\tEnter number : ");
            scanf("%d",&n);
            ADDTERM(id,n);
        }
        if(strcmp(cmd,"s") == 0){
            for(Series* cur = head; cur != NULL ;cur = cur->next){
                printf("\tId : %d\t",cur->id);
                for(Number* present = cur->numbers; present != NULL; present = present->next){
                    printf("\t%d",present->number);
                }
                printf("\n");
            }
        }
    }while(strcmp(cmd,"Exit") != 0);
    // CREATE(1);
    // ADDTERM(1,4);
    // ADDTERM(1,7);
    // ADDTERM(1,11);
    // CREATE(2);
    // ADDTERM(2,9);
    // for(Series* cur = head; cur != NULL ;cur = cur->next){
    //     printf("\tId : %d\t",cur->id);
    //     for(Number* present = cur->numbers; present != NULL; present = present->next){
    //         printf("\t%d",present->number);
    //     }
    //     printf("\n");
    // }
    // printf("\n\n");
}