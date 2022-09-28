#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 1007

int n;
int S[M];

typedef struct Rent{
    int dayStart;
    int dayEnd;
    int revenue;
    struct Rent *left;
    struct Rent *right;
}Rent;

int Hash(int a)
{
    return a%M;
}

Rent *ArrRent[M];

Rent *MakeRent(int dayStart, int dayEnd, int revenue)
{
    Rent *r = (Rent *)malloc(sizeof(Rent));
    r->dayStart = dayStart;
    r->dayEnd = dayEnd;
    r-> revenue = revenue;
    return r;
}

Rent* InsertIntoTree(int dayStart, int dayEnd, int revenue,Rent *r)
{
    if(r == NULL) 
        r = MakeRent(dayStart,dayEnd,revenue);
    if(dayEnd < r->dayEnd)
        r->left = InsertIntoTree(dayStart,dayEnd,revenue,r->left);
    if(dayEnd < r->dayEnd)
        r->right = InsertIntoTree(dayStart,dayEnd,revenue,r->right);
    return r;
}

Rent *FindFromTree(int dayStart, int dayEnd,Rent *r)
{
    if(r == NULL) return NULL;
    if(r->dayStart == dayStart && r->dayEnd == dayEnd)
        return r;
    if(dayEnd < r->dayEnd)
        return FindFromTree(dayStart, dayEnd, r->left);
    if(dayEnd > r->dayEnd)
        return FindFromTree(dayStart, dayEnd, r->right);
}

void INSERT(int dayStart, int dayEnd, int revenue)
{
    int hash = Hash(dayStart);
    ArrRent[hash] = InsertIntoTree(dayStart,dayEnd,revenue,ArrRent[hash]);
}

Rent *FIND(int dayStart, int dayEnd)
{
    int hash = Hash(dayStart);
    return FindFromTree(dayStart, dayEnd, ArrRent[hash]);
}

int Min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int dayStart,dayEnd,profit;
        scanf("%d%d%de",&dayStart,&dayEnd,&profit);
        INSERT(dayStart,dayEnd,profit);
    }
    
}