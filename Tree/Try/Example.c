#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
    int id;
    struct Node* leftChild;
    struct Node* rightSibling;
}Node;

Node* root[10001];
int size = 0;

Node *Find(int v, Node* r)
{
    if(r == NULL)
        return NULL;
    if(r->id == v)
        return r;
    Node *p = Find(v, r->leftChild);
    if(p != NULL) return p;
    return Find(v, r->rightSibling);
}

Node *FindNode(int v)
{
    for(int i = 0; i < size; i++){
        Node *find = Find(v,root[i]);
        if(find != NULL) return find;
    }
    return NULL;
}

Node* MakeNode(int v)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = v;
    p->leftChild = NULL;
    p->rightSibling = NULL;
    return p;
}

void PostOrder(Node* r)
{
    if(r == NULL) return;
    printf("\t%d",r->id);
    PostOrder(r->leftChild);
    PostOrder(r->rightSibling);
}

void AddChild(int u, int v)
{
    Node *child = FindNode(u);
    Node *parent = FindNode(v);
    if(parent == NULL){
        parent = MakeNode(v);
        root[size] = parent;
        size++;
        if(child == NULL)
            child = MakeNode(u);
        parent->leftChild = child;
    }
    else{
        if(child == NULL)
            child = MakeNode(u);
        if(parent ->leftChild == NULL)
            parent->leftChild = child;
        else {
            Node* right = parent ->leftChild;
            while(right->rightSibling != NULL) right = right->rightSibling;
            right->rightSibling = child;
        }
    }

}

void Show(int X)
{
    Node* p = FindNode(X);
    if(p != NULL)
        PostOrder(p);
}

int main(){
    int u,v;
    while(1){
        printf("Enter child,parent : ");
        scanf("%d",&u);
        if(u == -1)
            break;
        scanf("%d",&v);
        AddChild(u,v);
    }
    while(1){
    printf("\nEnter number to show descendants : ");
    int n;
    scanf("%d",&n);
    if(n ==-1) break;
    Show(n);
    }
}