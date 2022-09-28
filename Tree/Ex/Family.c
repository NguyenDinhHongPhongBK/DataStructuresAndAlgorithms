#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

typedef struct Family{
    char name[MAX];
    struct Family *leftMostChild;
    struct Family *rightSibling;
}Family;

Family *roots[10001];
int n;

Family *MakeRoot(char *name)
{
    Family * f = (Family *)malloc(sizeof(Family));
    strcpy(f->name, name);
    f->leftMostChild = NULL;
    f->rightSibling = NULL;
    return f;
}

Family *Find(char *name)
{
    for(int i = 0;i<n;i++){
        if(strcmp(name,roots[i]->name) == 0)
            return roots[i];
    }
    return NULL;
}

void InsertNode(Family *f)
{
    n++;
    roots[n+1] = f;
}
void AddChild(Family *child,Family *parent)
{
    // if(parent->leftMostChild == NULL){
    //     parent->leftMostChild =child;
    //     return;
    // }
    child->rightSibling = parent->leftMostChild;
    parent->leftMostChild = child;
}

int CountDescendants(Family *f)
{
    if(f == NULL) return 0;
    int cnt = 1;
    Family * p = f->leftMostChild;
    while(p != NULL){
        cnt += CountDescendants(p);
        p = p->leftMostChild;
    }
    return cnt;
}

int Generation(Family *f){
    if(f == NULL) return 0;
    int max = 0;
    for(Family * cur =f->leftMostChild;cur!=NULL;cur=cur->rightSibling ){
        int h = Generation(cur);
        if(h > max)
            max = h;
    }
    return max+1;
}


int main()
{
    char childName[MAX];
    char parentName[MAX];
    while(1){
        scanf("%s",&childName);
        if(strcmp(childName,"***") == 0)
            break;
        scanf("%s",&parentName);
        Family *child = Find(childName);
        Family *parent = Find(parentName);
        if(child == NULL){
            child = MakeRoot(childName);
            InsertNode(child);
        }
        if(parent == NULL){
            parent = MakeRoot(parentName);
            InsertNode(parent);
        }
        AddChild(child,parent);
    }

    char cmd[MAX],cmdName[MAX];
    while(1){
        scanf("%s",&cmd);
        if(strcmp(cmd,"***") == 0)
            break;
        scanf("%s",&cmdName);
        Family *f = Find(cmdName);
        if(strcmp(cmd,"descendants") ==0){
            int ans = CountDescendants(f);
            printf("%d\n",ans - 1);
        }
        if(strcmp(cmd,"generation") ==0){
            int ans = Generation(f);
            printf("%d",ans - 1);
        }
    }
    return 0;
}