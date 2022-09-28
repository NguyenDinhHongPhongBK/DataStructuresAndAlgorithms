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

int Left(int value, Node* root )
{
    return value < root->id;
}
 
int Right(int value, Node* root  )
{
    return value > root->id;
}

Node* Insert(Node* root,int value)
{
    if (root == NULL)
    {
        root = MakeNode(value);
    }
    if (Left(value,root))
        root->leftChild = Insert(root->leftChild, value);
    else if (Right(value,root))
        root->rightChild = Insert(root->rightChild,value);
    return root;
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

int main(){
    int u;
    char cmd[200];
    do{
        scanf("%s",&cmd);
        if(strcmp(cmd, "Insert") == 0){
            scanf("%d",&u);
            root = Insert(root,u);
        }
        if(strcmp(cmd,"preorder") == 0){
            PreOrder(root);
            printf("\n");
        }
        if(strcmp(cmd,"postorder") == 0){
            PostOrder(root);
            printf("\n");   
        }
    }while(strcmp(cmd,"#") != 0);

}