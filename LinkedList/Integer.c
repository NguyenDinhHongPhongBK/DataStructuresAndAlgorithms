#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int number;
    struct Node *next;
}Node;

Node *CreateNode(int X)
{
    Node *n = (Node*)malloc(sizeof(Node));
    n->number = X;
    n->next = NULL;
    return n;
}

void PrintNode(Node *head)
{
    printf("\nLinked list : \n");
    Node *cur = head;
    for(cur = head; cur != NULL; cur = cur->next){
        printf("\t%d",cur->number);
    }
}

Node *InsertTail(Node *head, int X)
{
    Node *newNode = CreateNode(X);
    if(head == NULL) 
        head = newNode;
    else{
        Node *last = head; 
        while (last->next != NULL) 
            last = last->next; 
        last->next = newNode;
    }
    return head;
}

// Node *InputNode(Node *head, int k)
// {
//     printf("Enter number of elemets in linked list : ");
//     scanf("%d",&k);
//     for(int i=0; i<k; i++){
//         int p;
//         printf("Enter integer for node %d : ",i+1);
//         scanf("%d",&p);
//         head = InsertTail(head,p);
//     }
//     return head;
// }

Node *InsertHead(Node *head, int X)
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

Node *InsertAfterCur(Node *head, Node *cur, int X)
{
    Node *newNode = CreateNode(X);
    if(head == NULL)
        head = newNode;
    else{
        newNode->next = cur->next ;
        cur->next = newNode;
    }
    return newNode;
}

Node *InsertBeforeCur(Node *head, Node *cur, int X)
{
    Node *newNode = CreateNode(X);
    if(head == NULL)
        head = newNode;
    else if (cur == head) { 
        head = newNode;
        newNode->next = cur;
    }
    else{
        Node *prev = head;
        while(prev->next != cur->next)
            prev = prev->next;
        prev->next = newNode ;
        newNode->next = cur;
    }
    return newNode;
}

Node *DeleteElement(Node *head, Node *delete)
{
    if(head == delete){ //Delete first element
        head->next = delete->next;
        free(delete);
    }
    else{
        Node *prev;
        while (prev->next !=delete)
            prev = prev->next;
        prev->next = delete->next;
        free(delete);
    }
    return head;
}

Node *DeleteAll(Node *head)
{
    Node *remove = head;
    while(remove != NULL){
        head = head->next;
        free(remove);
        remove = head;
    }
    return head;
}

int CheckEmpty(Node *head) 
{
    if (head == NULL) 
        return 1;
    else return 0;
}

int main()
{
    int k,p,position,count = 0;
    Node *cur;
    Node *head = NULL;
    Node *primitive = NULL;
    //Add element in linked list
    printf("Enter number of elemets in linked list : ");
    scanf("%d",&k);
    for(int i=0; i<k; i++){
        int p;
        printf("Enter integer for node %d : ",i+1);
        scanf("%d",&p);
        head = InsertTail(head,p);
    }

    PrintNode(head);
    printf("\nEnter value to add to the begining of list : ");
    scanf("%d",&p);
    head = InsertHead(head,p);
    PrintNode(head);
    head = DeleteAll(head);
}