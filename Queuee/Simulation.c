#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int A[20];
int count = 0;

typedef struct Node
{
    int number;
    struct Node* next;
}Node;

Node* head;
Node* tail = NULL;

int queueEmpty(){
    return head == NULL && tail == NULL;
}

Node *CreateNode(int X)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->number = X;
    newNode->next = NULL;
    return newNode;
}

void PushLast(int X) 
{
    Node *newNode = CreateNode(X);
    if(queueEmpty()){
        head = newNode;
        tail = newNode;
        return ;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

int PopHead()
{
    if(queueEmpty()){
        return -1;
    }
    else{
        Node *tmp = head;
        int v = head->number;
        head = head->next;
        if(head==NULL)
            tail = NULL;
        free(tmp);
        return v;
    }
}

void Show(Node* head){
    for(Node *cur = head; cur != NULL; cur = cur->next){
        printf("\t%d",cur->number);
    }
}

int main()
{
    char cmd[15];
    do{
        printf("\nEnter command : ");
        scanf("%s",&cmd);
        if(strcmp(cmd,"PUSH") == 0){
            int value;
            printf("Enter value to add last : ");
            scanf("%d",&value);
            PushLast(value);
            Show(head);
        }
        else if(strcmp(cmd,"POP") == 0){
            A[count] = PopHead();
            count++;
            Show(head);
        }
    }while(strcmp(cmd,"#") != 0);

    for(int i=0;i<count;i++){
        if(A[i] == -1){
            printf("NULL\n");
        }
        printf("%d\n",A[i]);
    }
}