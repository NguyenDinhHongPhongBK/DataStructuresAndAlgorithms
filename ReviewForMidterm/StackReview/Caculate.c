#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count=0;

typedef struct Number{
    int number;
    struct Number* next;
}Number;

Number *headNumber;

typedef struct Parenthesis{
    char parenthesis;
    struct Parenthesis* next;
}Parenthesis;

Parenthesis *headParenthesis;

Number *CreateNumber(int X)
{
    Number *a = (Number *)malloc(sizeof(Number));
    a->number = X;
    a->next = NULL;
    return a;
}

Parenthesis *CreateParenthesis(char X)
{
    Parenthesis *a = (Parenthesis *)malloc(sizeof(Parenthesis));
    a->parenthesis = X;
    a->next = NULL;
    return a;
}

int IsEmptyNumber()
{
    return headNumber == NULL;
}

int IsEmptyParenthesis()
{
    return headParenthesis == NULL;
}

void PushHeadNumber(int a) // Add first
{
    Number *S = CreateNumber(a);
    if(IsEmptyNumber()){
        headNumber = S;
    }else{
        S->next = headNumber;
        headNumber = S;
    }
}

void PushHeadParenthesis(char a) // Add first
{
    Parenthesis *S = CreateParenthesis(a);
    if(IsEmptyParenthesis()){
        headParenthesis = S;
    }else{
        S->next = headParenthesis;
        headParenthesis = S;
    }
}

int PopHeadNumber()
{
    if(IsEmptyNumber())
        return -1;
    Number *cur = headNumber;
    int a = headNumber->number;
    headNumber = cur->next;
    free(cur);
    return a;
}

char PopHeadParenthesis()
{
    if(IsEmptyParenthesis())
        return 1;
    Parenthesis *cur = headParenthesis;
    char a = headParenthesis->parenthesis;
    headParenthesis = cur->next;
    free(cur);
    return a;
}

int main(){
    
}