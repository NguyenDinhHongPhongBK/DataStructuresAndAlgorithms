#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack{
    int number;
    struct Stack* next;
}Stack;

Stack* head;
Stack* tail = NULL;

Stack* CreateStack(int X)
{
    Stack *p = (Stack*)malloc(sizeof(Stack));
    p->number = X;
    p->next = NULL;
    return p;
}

int IsEmptyStack(){
    return head == NULL && tail == NULL;
}

void PUSH(int X)
{
    Stack *newStack = CreateStack(X);
    if(IsEmptyStack()){
        head = newStack;
        tail = newStack;
    }else{
        tail->next = newStack;
        tail = newStack;
    }
}

int POP()
{
    if(IsEmptyStack())
        return -1;
    else{
        Stack *newStack = head;
        int result = head->number;
        head = head->next;
        if(head == NULL)
            tail = NULL;
        free(newStack);
        return result;
    }
}

void PrintStack(Stack* head)
{
    for(Stack *cur = head; cur; cur = cur->next){
        printf("%d\t", cur->number);
    }
}

int main()
{
    char cmd[20];
    do{
        //printf("\nEnter command : ");
        scanf("%s",&cmd);
        if(strcmp(cmd,"PUSH") == 0){
            int a;
            // printf("Enter number to add first : ");
            scanf("%d",&a);
            PUSH(a);
        }else if(strcmp(cmd,"POP") == 0){
            int del = POP();
            if(del == -1)
                printf("\nNULL");
            else
                printf("\n%d",del);
            
        // }else if(strcmp(cmd,"SHOW") == 0){
        //     PrintStack(head);
        }
    }while(strcmp(cmd, "#") != 0);
    
}