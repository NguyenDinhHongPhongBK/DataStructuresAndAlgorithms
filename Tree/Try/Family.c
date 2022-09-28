#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct Family{
    char name[MAX];
    struct Family *leftMostChild;
    struct Family *rightSibling;
}Family;

Family *ancestor[10001];
int size = 0;

Family *CreateNode(char n[])
{
    Family *f = (Family*)malloc(sizeof(Family));
    strcpy(f->name, n);
    f->leftMostChild = NULL;
    f->rightSibling = NULL;
    return f;
}

Family *Find(char name[], Family *fam)
{
    if(fam == NULL) return NULL;
    if(strcmp(fam->name, name) == 0) return fam;
    Family *f = Find(name, fam->leftMostChild);
    if(f != NULL) return f;
    return Find(name,fam->rightSibling);
}

Family *FindName(char name[])
{
    for(int i = 0; i < size;i++){
        Family *f = Find(name,ancestor[i]);
        if(f != NULL) return f;
    }
    return NULL;
}

void AddChild(char childName[], char parentName[])
{
    Family *parent = FindName(parentName);
    Family *child = FindName(childName);
    if(parent == NULL){
        parent = CreateNode(parentName);
        ancestor[size] = parent;
        size ++;
        if(child == NULL)
            child = CreateNode(childName);
        parent->leftMostChild = child;
    }
    else{
        if(child == NULL) 
            child = CreateNode(childName);
        if(parent->leftMostChild == NULL)
            parent->leftMostChild = child;
        else{
            Family *last = parent->leftMostChild;
            while(last->rightSibling != NULL)
                last = last->rightSibling;
            last->rightSibling = child;
        }
    }
}

void PostOrder(Family *f)
{
    if(f == NULL) return;
    printf("  %s",f->name);
    PostOrder(f->leftMostChild);
    PostOrder(f->rightSibling);
}

void Show(char name[])
{
    Family* p = FindName(name);
    if(p != NULL){
        PostOrder(p);
    }
}

int CountDescendants(Family *f)
{
    if(f == NULL) return 0;
    int cnt = 1;
    Family * p = f->leftMostChild;
    while(p != NULL){
        cnt += CountDescendants(p);
        p = p->rightSibling;
    }
    return cnt;
}

int CountGeneration(Family *f)
{
    if(f == NULL) return 0;
    int max = 0;
    for(Family * cur =f->leftMostChild;cur!=NULL;cur=cur->rightSibling ){
        int h = CountGeneration(cur);
        if(h > max)
            max = h;
    }
    return max + 1;
}


int main()
{
    char cmd[MAX];
    char childName[MAX],parentName[MAX],name[MAX];
    int ans;
    while(1){
        //printf("Enter child and parent name : ");
        scanf("%s",&childName);
        if(strcmp(childName,"***") == 0)
            break;
        scanf("%s",&parentName);
        AddChild(childName,parentName);
    }
    

    while(1){
        //printf("\nEnter command : ");
        scanf("%s",&cmd);
         scanf("%s",&name);
        if(strcmp(cmd,"descendants") == 0){
            Family *f = FindName(name);
            if(f != NULL){
                ans = CountDescendants(f) - 1;
            }
            printf("%d\n",ans);
        }
        if(strcmp(cmd,"generation") == 0){
            Family *f = FindName(name);
            if(f != NULL){
                ans = CountGeneration(f) - 1;
            }
            printf("%d\n",ans);
        }
        if(strcmp(cmd,"***") == 0) break;
    }
}