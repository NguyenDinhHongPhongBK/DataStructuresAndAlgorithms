#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char Parenthesis;
    struct Node* next;
}Node;

Node* top;
char s[1000000];
Node* CreateNode(char a){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->Parenthesis = a;
    newNode->next = NULL;
    return newNode;
}

void initStack(){
    top = NULL;
}

int stackEmpty(){
    return top == NULL;
}

void Push(char x){
    Node* p = CreateNode(x);
    p->next = top;
    top = p;
}

char Pop(){
    if(stackEmpty())
        return 0;
    char x = top->Parenthesis;
    Node* p = top;
    top = top->next;
    free(p);
    return x;
}
int CheckParenthesis(char a){
    if(a !='{' && a != '}' && a != '(' && a!=')' && a != '[' && a != ']') 
        return 0;
    else 
        return 1;
}

int Match(char a,char b){
    if(a == '[' && b == ']')
        return 1;
    if(a == '(' && b == ')')
        return 1;
    if(a == '{' && b =='}')
        return 1;
    return 0;
}

int CheckMatch(char *s){
    initStack();
    for(int i=0;i<strlen(s);i++){
        if(s[i]== '{' || s[i] == '(' || s[i] == '['){
            Push(s[i]);
        }
        else{
            if(stackEmpty())
                return 0;
            char c = Pop();
            if(!Match(c,s[i]))
                return 0;
        }
    }
    return stackEmpty();
}
int main(){
    printf("Enter string : ");
    scanf("%s",&s);
    // int flag = 1;
    // for(int i=0;i<strlen(s);i++){
    //     if(CheckParenthesis(s[i] == 0)){
    //         flag=0;break;
    //     }
    // }
    // if(flag == 1){
        int a = CheckMatch(s);
        printf("%d",a);
    //}
}
