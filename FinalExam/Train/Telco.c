#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define M  100007

int Hash(char *s)
{
    int c = 0;
    for(int i = 0 ; i< strlen(s); i ++){
        c = (c*256 + s[i]) % M;
    }
    return c;
}

typedef struct Tree{
    char fromNumber[20];
    int nbCalls;
    int durations;
    struct Tree *left;
    struct Tree *right;
}Tree;

Tree *ArrRoot[M];

Tree* CreateNode(char *phoneNumber,int nbCalls,int durations)
{
    Tree *n = (Tree*) malloc(sizeof(Tree));
    strcpy(n->fromNumber,phoneNumber);
    n->nbCalls = nbCalls;
    n->durations = durations;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Tree* InsertToTree(Tree *root, char *phoneNumber,int call, int durations)
{
    if(root == NULL) 
        root = CreateNode(phoneNumber,call,durations);
    int a = strcmp(root->fromNumber,phoneNumber);
    if(a == 0)
        return root;
    if(a > 0)
        root->left = InsertToTree(root->left,phoneNumber,call,durations);
    else
        root->right = InsertToTree(root->right,phoneNumber,call,durations);
    return root;
}

Tree *FindFromTree(char *fromNumber,Tree *root){
    if(root == NULL) return NULL;
    int c = strcmp(root->fromNumber,fromNumber);
    if(c == 0) return root;
    if(c < 0)
        return FindFromTree(fromNumber,root->right);
    else
        return FindFromTree(fromNumber,root->left);

}

Tree*FIND(char *phoneNumber)
{
    int hash = Hash(phoneNumber);
    if(ArrRoot[hash] == NULL) return NULL;
    Tree *f = FindFromTree(phoneNumber,ArrRoot[hash]);
    return f;
}