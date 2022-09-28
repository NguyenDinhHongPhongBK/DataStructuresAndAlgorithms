#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int A[20];
int count=0;
typedef struct Node{
    int number;
    struct Node* next;
}Node;

Node * CreateNode(int X)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->number = X;
    newNode->next = NULL;
    return newNode;
}

void ShowList(Node *head)
{
    Node *cur = head;
    for(cur = head; cur != NULL; cur = cur->next)
        printf("%d ",cur->number);
}

Node *AddFirst(Node *head, int X)
{
        Node *newNode = CreateNode(X);
        if(head == NULL) 
            head = newNode;
        else{
            newNode->next = head;
            head = newNode;
        }
        return head;
}

Node *DeleteFirst(Node *head)
{
    Node *cur = head;
    if(head == NULL) 
    {
        return NULL;
    }
    count++;
    A[count] = head->number;
    head = cur->next;
        free(cur);
    return head;
}



int main(){
    struct Node* head = NULL;
    int n,add,delete,key;
    char cmd[20];

    do{
        // printf("\nEnter command : ");
        scanf("%s",&cmd);
        if(strcmp(cmd,"PUSH") == 0){
            // printf("Enter number to add : ");
            scanf("%d",&add);
            head = AddFirst(head,add);
            // ShowList(head);
        }
        else if(strcmp(cmd,"POP") == 0){
            head = DeleteFirst(head);
            // ShowList(head);
        }
        

    }while(strcmp(cmd,"#") != 0);

    for(int j=1;j<=count;j++){
        printf("%d\n",A[j]);
    }
}