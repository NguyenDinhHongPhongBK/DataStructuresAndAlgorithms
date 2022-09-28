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

Tree *Find(Tree *r,int v)
{
    if(r == NULL) return;
    if(r->number == v) return r;
    Tree *p =Find(r->leftMostChild,v);
    if(p->rightSibling != NULL) return p;
    return Find(p->rightSibling,v);
}

int main()
{

}