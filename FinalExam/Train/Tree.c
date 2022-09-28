#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Tree{
    int number;
    struct Tree *leftmostchild;
    struct Tree *rightsibling;
}Tree;

Tree *root;

Tree *CreateNode(int X)
{
    Tree *tr = (Tree *)malloc(sizeof(Tree));
    tr->number = X;
    tr->leftmostchild = NULL;
    tr->rightsibling = NULL;
    return tr;
}

Tree *FindNode(int X, Tree *r)
{
    if(r == NULL) return NULL;
    if(r -> number == X) return r;
    Tree *tr = FindNode(X,r->leftmostchild);
    if(tr != NULL) return tr;
    return FindNode(X,r->rightsibling);
}

void INSERT(int u, int v)
{
    Tree *newTree = FindNode(u, root);
    Tree *parentTree = FindNode(v, root);
    if(newTree == NULL && parentTree != NULL)
    {
        Tree *newTree = CreateNode(u);
        if(parentTree->leftmostchild == NULL)
            parentTree->leftmostchild = newTree;
        else{
            Tree *sibling = parentTree->leftmostchild;
            while(sibling->rightsibling != NULL){
                sibling = sibling->rightsibling;
            }
            sibling->rightsibling = newTree;
        }
    } 
}

int CountDescendants(Tree *r)
{
    if(r == NULL) return 0;
    int a = CountDescendants(r->leftmostchild);
    int b = CountDescendants(r->rightsibling);
    return a + b + 1;
}

int CountHeight(Tree *f){
    if(f == NULL) return 0;
    int max = 0;
    for(Tree * cur =f->leftmostchild;cur!=NULL;cur=cur->rightsibling ){
        int h = CountHeight(cur);
        printf("%d  ",h);
        if(h > max)
            max = h;
    }
    return max+1;
}

void BreadthFirst(Tree *r)
{
    if(r == NULL) return;
    
}

void PREORDER(Tree *t)
{
    if(t == NULL) return;
    printf("%d ",t->number);
    PREORDER(t->leftmostchild);
    PREORDER(t->rightsibling);
}

void POSTORDER(Tree *t)
{
    if(t == NULL) return;
    POSTORDER(t->leftmostchild);
    printf("%d ",t->number);
    POSTORDER(t->rightsibling);
    printf("\n");
}

void INORDER(Tree *t)
{
    if(t == NULL) return;
    INORDER(t->leftmostchild);
    printf("%d ",t->number);
    Tree *tr = t->leftmostchild;
    if(tr != NULL) 
        tr = tr->rightsibling;
    while(tr != NULL){
        INORDER(tr);
        tr = tr->rightsibling;
    }
    printf("\n");

}

int main()
{
    root = CreateNode(1);
    INSERT(2,1);
    INSERT(3,2);
    INSERT(4,1);
    INSERT(5,1);
    INSERT(6,3);
    INSERT(7,4);
    PREORDER(root);
    printf("\n%d",CountDescendants(root) - 1);
    printf("\n----------------");
    Tree *f = FindNode(2,root);
    printf("\n%d",CountDepth(root,f));
}