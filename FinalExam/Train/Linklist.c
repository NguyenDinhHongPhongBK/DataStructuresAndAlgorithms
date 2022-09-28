#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int number;
    struct Node* next;
}Node;

Node *head,*tail;

Node *CreateNode(int number)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->number = number;
    p->next = NULL;
    return p;
}

int CheckAppear(int u)
{
    Node *cur = head;
    if(cur == NULL)
        return 0;
    while(cur != NULL){
        if(cur->number == u)
            return 1;
        cur = cur->next;
    }
    return 0;
}

void InsertHead(int u)
{
    if(CheckAppear(u) == 1) return;
    Node *p = CreateNode(u);
    if(head == NULL){
        head = p;
        tail = p;
    }
    else{
        p->next = head;
        head = p;
    }
}

void InsertTail(int u)
{
    if(CheckAppear(u) == 1) return;
    Node *p = CreateNode(u);
    if(head == NULL){
        head = p;
        tail = p;
    }
    else{
        tail->next = p;
        tail = p;
    }
}
void InsertAfter(int u, int v)
{
    if(CheckAppear(u) == 1) return;
    if(CheckAppear(v) == 0) return;
    Node *p = CreateNode(u);
    if(tail->number == v){
        tail->next = p;
        tail = p;
    }
    else{
        Node *cur = head;
        while(cur->number != v) cur = cur->next;
        p->next = cur->next;
        cur->next = p;
    }
}

void InsertBefore(int u, int v)
{
    if(CheckAppear(u) == 1) return;
    if(CheckAppear(v) == 0) return;
    Node *p = CreateNode(u);
    if(head->number == v){
        p->next = head;
        head = p;
    }
    else{
        Node *cur = head;
        while(cur->next->number != v) cur = cur->next;
        p->next = cur->next;
        cur->next = p;
    }
}

void Delete(int u)
{
    if(CheckAppear(u) == 0) return;
    if(head->number == u){
        Node * cur = head;
        head = head->next;
        free(cur);
    }
    else{
        Node *cur = head;
        Node *prev = NULL;
        while(cur->number != u){
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        free(cur);
    }
}

void Show(Node *h)
{
    Node *cur;
    for(cur = head;cur != NULL;cur = cur->next)
        printf("\t%d",cur->number);
    printf("\n");
}

int main()
{
    InsertHead(1);
    InsertHead(2);
    InsertTail(3);
    InsertTail(4);
    InsertAfter(5,3);
    InsertAfter(6,4);
    InsertBefore(7,2);
    InsertBefore(8,6);
    Show(head);
    Delete(7);
    Show(head);
    Delete(4);
    Show(head);
    Delete(5);
    Show(head);
}     