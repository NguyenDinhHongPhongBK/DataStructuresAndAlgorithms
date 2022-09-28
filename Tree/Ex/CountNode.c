#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Tree{
    int number;
    struct Tree *leftMostChild;
    struct Tree *rightSibling;
}Tree;

Tree *root;

Tree *CreateNode(int X)
{
    Tree *tr = (Tree *)malloc(sizeof(Tree));
    tr->number = X;
    tr->leftMostChild = NULL;
    tr->rightSibling = NULL;
    return tr;
}

Tree *Find(int X, Tree *r)
{
    if(r == NULL) return NULL;
    if(r->number == X) return r;
    Tree *tr = Find(X, r->leftMostChild);
    if(tr != NULL) return tr;
    return Find(X, r->rightSibling);
}

void Insert(int u, int v)
{
    Tree *newTree = Find(u,root);
    Tree *parentTree = Find(v,root);
    if(newTree == NULL && parentTree != NULL)
    {
        Tree *newTree = CreateNode(u);
        if(parentTree->leftMostChild == NULL)
            parentTree->leftMostChild = newTree;
        else{
            Tree *sibling = parentTree->leftMostChild;
            while(sibling->rightSibling != NULL){
                sibling = sibling->rightSibling;
            }
            sibling->rightSibling = newTree;
        }
    } 
}

int countNode = 0;
void CountChild(Tree *r)
{
    if(r->leftMostChild != NULL){
        countNode++;
        Tree*sibling = r->leftMostChild;
        while(sibling->rightSibling != NULL){
            sibling = sibling->rightSibling;
            countNode++;
        }
    }
    
}
int countLeaf = 0;
int CountLeaf(Tree *r)
{
    if(r == NULL) return 0;
    if(r->leftMostChild == NULL) return 1;
    int cnt = 0;
    Tree *p = r->leftMostChild;
    while(p != NULL){
        cnt += CountLeaf(p);
        p = p->rightSibling;
    }
    return cnt;
}

int CountLeaves(int u)
{
    int a;
    Tree *tr = Find(u,root);
    if(tr != NULL){
        a = CountLeaf(tr);
    }
    return a;
}

int countChild = 0;

void Counttt(Tree *r, int v)
{
    if(r == NULL) return ;
    CountChild(r);
    if(countNode == v)
        countChild++;
    countNode = 0;
    Counttt(r->leftMostChild, v);
    Counttt(r->rightSibling,v);
}

void CountKChildren(int u,int v)
{
    Tree *tr = Find(u,root);
    Counttt(tr,v);
}

int main()
{
    char cmd[20];
    int u,v;
    do{
        scanf("%s",&cmd);
        if(strcmp(cmd, "MakeRoot") == 0){
            scanf("%d",&u);
            root = CreateNode(u);
        }
        if(strcmp(cmd,"Insert") == 0){
            scanf("%d",&u);
            scanf("%d",&v);
            Insert(u,v);
        }
        if(strcmp(cmd,"CountLeaves") == 0){
            scanf("%d",&u);
            printf("%d\n",CountLeaves(u));
            countLeaf = 0;            
        }
        if(strcmp(cmd,"CountKChildren") == 0){
            scanf("%d",&u);
            scanf("%d",&v);
            CountKChildren(u,v);
            printf("%d\n",countChild);
            countChild = 0;            
        }
    }while(strcmp(cmd,"*") != 0);
}