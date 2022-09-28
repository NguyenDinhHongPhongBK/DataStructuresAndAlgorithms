#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct BinarySearchTree{
    int value;
    struct BinarySearchTree *leftChild;
    struct BinarySearchTree *rightChild;
    struct BinarySearchTree *parent;
}BinarySearchTree;

BinarySearchTree *root;

BinarySearchTree *CreateNode(int x)
{
    BinarySearchTree *bst = (BinarySearchTree *)malloc(sizeof(BinarySearchTree));
    bst->value = x;
    bst->leftChild = NULL;
    bst->rightChild = NULL;
    bst->parent = NULL;
    return bst;
}

BinarySearchTree *Insert(int x, BinarySearchTree *r)
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

BinarySearchTree *Search(int x,BinarySearchTree *r)
{
    if(r == NULL) return NULL;
    if(r->value == x) return r;
    else if(r->value < x)
        return Search(x,r->rightChild);
    else
        return Search(x,r->leftChild);
}

BinarySearchTree *FindMax(BinarySearchTree *r)
{
    if(r == NULL) return NULL;
    if(r->rightChild == NULL) return r;
    return FindMax(r->rightChild);
}

BinarySearchTree *FindMin(BinarySearchTree *r)
{
    if(r == NULL) return NULL;
    if(r->leftChild == NULL) return r;
    return FindMin(r->leftChild);
}

BinarySearchTree *FindPredecessor(BinarySearchTree *x, BinarySearchTree *r)
{
    if(x->leftChild != NULL) 
        return FindMax(x->leftChild);
    else{
        BinarySearchTree *p = x->parent;
        while(p != NULL && p->leftChild == x){
            x = p;
            p = p->parent;
        }
        return p;
    }
}

BinarySearchTree *Delete(int x, BinarySearchTree *r)
{
    if(r == NULL) return r;
    if(x < r->value)
        r->leftChild = Delete(x, r->leftChild);
    else if(x > r->value)
        r->rightChild = Delete(x, r->rightChild);
    else{   // root->value == x
        if(r->leftChild == NULL){
            BinarySearchTree *newRoot = r->rightChild;
            free(r);
            return newRoot;
        }
        if(r->rightChild == NULL){
            BinarySearchTree *newRoot = r->leftChild;
            free(r);
            return newRoot;
        }
        r->value = FindMin(r->rightChild)->value;
        r->rightChild = Delete(r->value,r->rightChild);
    }
    return r;
}

void PreOrder(BinarySearchTree* r)
{
    if(r == NULL) return;
    printf("%d ",r->value);
    PreOrder(r->leftChild);
    PreOrder(r->rightChild);
}

void PostOrder(BinarySearchTree* r)
{
    if(r == NULL) return;
    PostOrder(r->leftChild);
    PostOrder(r->rightChild);
    printf("%d ",r->value);
}

void InOrder(BinarySearchTree* r)
{
    if(r == NULL) return;
    InOrder(r->leftChild);
    printf("%d ",r->value);
    InOrder(r->rightChild);
}

int Height(BinarySearchTree * r)
{
    if (r == NULL)
        return 0;
    else {
        int lheight = Height(r->leftChild);
        int rheight = Height(r->rightChild);
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void printCurrentLevel(BinarySearchTree *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->value);
    else if (level > 1) {
        printCurrentLevel(root->leftChild, level - 1);
        printCurrentLevel(root->rightChild, level - 1);
    }
}
void BreadthFirst(BinarySearchTree *root)
{
    int h = Height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

int main()
{
    int u;
    char cmd[200];
    root = Insert(5,root);
    root =Insert(9,root);
    root =Insert(2,root);
    root =Insert(1,root);
    root =Insert(8,root);
    root =Insert(5,root);
    root =Insert(10,root);
    root =Insert(4,root);
    root =Insert(11,root);
    root =Insert(12,root);
    printf("\nPreorder  : ");
    PreOrder(root);
    printf("\nPostOrder : ");
    PostOrder(root);
    printf("\nInorder   : ");
    InOrder(root);
    BinarySearchTree *max = FindMax(root);
    printf("\nMaximun value : %d",max->value);
    BinarySearchTree *min = FindMin(root);
    printf("\nMinimum value : %d",min->value);
    int x = 10;
    BinarySearchTree *ten = Search(x,root);
    if(ten != NULL){
        BinarySearchTree *preTen = FindPredecessor(ten,root);
        if(preTen != NULL)
            printf("\nPredecessor of 10 is %d",preTen->value);
    }
    // root = Delete(10,root);
    // printf("\nInorder   : ");
    // InOrder(root);
    printf("\nBreadth first   : ");
    BreadthFirst(root);
    printf("\nHeight : %d",Height(root));
}