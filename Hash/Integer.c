#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000000

int A[MAX];
int n;

typedef struct Node{
    int number;
    struct Node* next;
}Node;

Node *ArrayNode[MAX];

Node *CreateNode(int X)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->number = X;
    newNode->next = NULL;
    return newNode;
}

int Hash(int X)
{
    return X%10007;
}

Node *InsertHead(Node *head,Node *p)
{
    if(head == NULL) 
        head = p;
    else{
        p->next = head;
        head = p;
    }
    return head;
}

void INSERT(int X)
{
    Node *p = CreateNode(X);
    int k = Hash(X);
    ArrayNode[k] = InsertHead(ArrayNode[k],p);
}

Node* FIND(int X)
{
    int a = Hash(X);
    Node *cur = ArrayNode[a];
    if(cur == NULL) return NULL;
    while(cur != NULL){
        if(cur->number == X) return cur;
        cur = cur->next;
    }
    return NULL;
}



int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        A[i] = rand()%100000;
        printf("%d  ",A[i]);
        INSERT(A[i]);
    }
    int a = 17035;
    Node *f = FIND(a);
    if(f == NULL)
        printf("\n%d is not exist in this list",a);
    else
        printf("\n%d is exist in this list",a);
}