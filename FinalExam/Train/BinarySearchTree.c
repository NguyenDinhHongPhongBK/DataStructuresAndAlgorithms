#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Tree{
    int value;
    struct Tree *leftChild;
    struct Tree *rightChild;
    struct Tree *parent;
}Tree;

Tree *root;

Tree *CreateNode(int x)
{
    Tree *bst = (Tree *)malloc(sizeof(Tree));
    bst->value = x;
    bst->leftChild = NULL;
    bst->rightChild = NULL;
    bst->parent = NULL;
    return bst;
}

Tree *Insert(int x, Tree *r)
{
    if(r == NULL)
        r  = CreateNode(x);
    if(x < r->value){
        r->leftChild = Insert(x,r->leftChild);
        r->leftChild->parent = r;
    }
    else if(x > r->value){
        r->rightChild = Insert(x,r->rightChild);
        r->rightChild->parent = r;
    }
    return r;    
}

Tree *Search(int x,Tree *r)
{
    if(r == NULL) return NULL;
    if(r->value == x) return r;
    else if(r->value < x)
        return Search(x,r->rightChild);
    else
        return Search(x,r->leftChild);
}

Tree *FindMax(Tree *r)
{
    if(r == NULL) return NULL;
    if(r->rightChild == NULL) return r;
    return FindMax(r->rightChild);
}

Tree *FindMin(Tree *r)
{
    if(r == NULL) return NULL;
    if(r->leftChild == NULL) return r;
    return FindMin(r->leftChild);
}

Tree *FindPredecessor(Tree *x, Tree *r)
{
    if(x->leftChild != NULL) 
        return FindMax(x->leftChild);
    else{
        Tree *p = x->parent;
        while(p != NULL && p->leftChild == x){
            x = p;
            p = p->parent;
        }
        return p;
    }
}

Tree *Delete(int x, Tree *r)
{
    if(r == NULL) return r;
    if(x < r->value)
        r->leftChild = Delete(x, r->leftChild);
    else if(x > r->value)
        r->rightChild = Delete(x, r->rightChild);
    else{   // root->value == x
        if(r->leftChild == NULL){
            Tree *newRoot = r->rightChild;
            free(r);
            return newRoot;
        }
        if(r->rightChild == NULL){
            Tree *newRoot = r->leftChild;
            free(r);
            return newRoot;
        }
        r->value = FindMin(r->rightChild)->value;
        r->rightChild = Delete(r->value,r->rightChild);
    }
    return r;
}

int main()
{
    
}