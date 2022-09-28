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
    FindNode(X,r->rightsibling);
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

void PREORDER(Tree *t)
{
    if(t == NULL) return;
    printf("%d ",t->number);
    PREORDER(t->leftmostchild);
    PREORDER(t->rightsibling);
    printf("\n");
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
    char cmd[20];
    int u,v;
    do{
        //printf("\nEnter command : ");
        scanf("%s",&cmd);
        if(strcmp(cmd, "MakeRoot") == 0){
            //printf("Enter id : ");
            scanf("%d",&u);\
            root = CreateNode(u);
        }
        if(strcmp(cmd,"Insert") == 0){
            //printf("Enter id to add : ");
            scanf("%d",&u);
            //printf("Enter id to add after : ");
            scanf("%d",&v);
            INSERT(u,v);
        }
        if(strcmp(cmd,"PreOrder") == 0){
            PREORDER(root);
        }
        if(strcmp(cmd,"PostOrder") == 0){
            POSTORDER(root);
        }
        if(strcmp(cmd,"InOrder") == 0){
            INORDER(root);
        }
    }while(strcmp(cmd,"*") != 0);
}