#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int id;
    struct Node* leftChild;
    struct Node* rightChild;
}Node;

Node* root;

Node* MakeNode(int v)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = v;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

Node *Find(int v, Node* r)
{
    if(r == NULL)
        return NULL;
    if(r->id == v)
        return r;
    Node *p = Find(v, r->leftChild);
    if(p != NULL) return p;
    return Find(v, r->rightChild);
}

void AddLeft(int u, int v)
{
    Node* p = Find(v,root);
    if(p == NULL) return;
    Node *q =Find(u,root);
    if(q != NULL) return;
    if(p->leftChild != NULL) return;
    q = MakeNode(u);
    p->leftChild = q;
}

void AddRight(int u, int v)
{
    Node* p = Find(v,root);
    if(p == NULL) return;
    Node *q =Find(u,root);
    if(q != NULL) return;
    if(p->rightChild != NULL) return;
    q = MakeNode(u);
    p->rightChild = q;
}

void PreOrder(Node* r)
{
    if(r == NULL) return;
    printf("%d ",r->id);
    PreOrder(r->leftChild);
    PreOrder(r->rightChild);
}

void PostOrder(Node* r)
{
    if(r == NULL) return;
    PostOrder(r->leftChild);
    PostOrder(r->rightChild);
    printf("%d ",r->id);
}

void InOrder(Node* r)
{
    if(r == NULL) return;
    InOrder(r->leftChild);
    printf("%d ",r->id);
    InOrder(r->rightChild);
}

int main()
{
    int u,v;
    char cmd[20];
    do{
        scanf("%s",&cmd);
        if(strcmp(cmd, "MakeRoot") == 0){
            scanf("%d",&u);\
            root = MakeNode(u);
        }
        if(strcmp(cmd,"AddLeft") == 0){
            scanf("%d",&u);
            scanf("%d",&v);
            AddLeft(u,v);
        }
        if(strcmp(cmd,"AddRight") == 0){
            scanf("%d",&u);
            scanf("%d",&v);
            AddRight(u,v);
        }
        if(strcmp(cmd,"PreOrder") == 0){
            PreOrder(root);
            printf("\n");
        }
        if(strcmp(cmd,"PostOrder") == 0){
            PostOrder(root);
            printf("\n");   
        }
        if(strcmp(cmd,"InOrder") == 0){
            InOrder(root);
            printf("\n");
        }
    }while(strcmp(cmd,"*") != 0);
}