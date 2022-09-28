#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Polynomial{
    int coefficient[100];
    int exponent[100];
    int id;
}Polynomial;

typedef struct Node{
    Polynomial polynomial;
    struct Node* next;
}Node;

Node *head;

Node *CreateElement(int id)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->polynomial.id = id;
    newNode->next = NULL;
    return newNode;
}

Node *Addlast(Node *head)
{
    
}

Node *CREATE(Node* head, int id)
{
    
}

Node *AddLast(Node *head,Node *newNode)
{
    if(head->next == NULL){
        head = newNode;
    }else{
        Node *last = head;
        while(last->next != NULL)
            last = last->next;
        last->next = newNode;
    }
    return head;
}

Node *ADDTERM(Node* head, int id, int coefficient, int exponent)
{
    if(head->id == id){
        Node* newNode = CreateElement(coefficient,exponent);
        AddLast(head,newNode);
    }
    return head;
}

void PRINT(Node *head,int id)
{
    if(head->id == id){
        for(Node *cur = head;cur->next !=NULL ; cur=cur->next){
            if(cur->next == NULL){
                printf("%d^%d",cur->polynomial.coefficient,cur->polynomial.exponent);
            }else{
                printf("%d^%d + ",cur->polynomial.coefficient,cur->polynomial.exponent);
            }
        }
    }
}

int main()
{
    char cmd[30];
    do{
        printf("Enter command : ");
        scanf("%s",&cmd);
        if(strcmp(cmd,"CREATE") == 0){
            Node *head;
            int id;
            printf("Enter id of this polynomial : ");
            scanf("%d",&id);
            head = CREATE(head,id);
        }
        if(strcmp(cmd,"PRINT") == 0){
            printf("Enter id of this polynomial to print : ");
            int id;
            scanf("%d",&id);
        }
    }while(strcmp(cmd, "#") != 0);
}