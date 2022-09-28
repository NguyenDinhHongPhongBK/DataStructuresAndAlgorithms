#include<iostream>
#include<stack>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

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
    stack<char> parenthesisStack;
    for(int i=0;i<strlen(s);i++){
        if(s[i] == '('){
            parenthesisStack.push(s[i]);
        }
        else if(s[i] == ')'){
            if(parenthesisStack.empty())
                return 0;
            char c = parenthesisStack.top();
            parenthesisStack.pop();
            if(!Match(c,s[i]))
                return 0;
        }
    }
    return parenthesisStack.empty();
}

bool Priority(char c1, char c2)
{
    if(c1 == '*' && (c2 == '+' || c2 == '-')) return true;
    if(c1 == '/' && (c2 == '+' || c2 == '-')) return true;
    return false;
}

bool IsOperand(char x)
{
    if(isalnum(x))
        return true;
    return false;
}

bool IsOpenBracket(char x)
{
    if(x == '(')
        return true;
    return false;
}

bool IsCloseBracket(char x)
{
    if(x == ')')
        return true;
    return false;
}

bool IsOperator(char x)
{
    if(x == '+' || x == '-' || x == '/' || x == '*' )
        return true;
    return false;
}

void ConvertToPostFix(char *s)
{
    string postfix ="";
    stack <char> express; 
    for(int i = 0; i < strlen(s); i++){
        char x = s[i];
        if(IsOperand(x)) 
            postfix += x;
        else if(IsOpenBracket(x))
            express.push(x);
        else if(IsOperator(x)){
            if(express.empty() || express.top() == '('  || Priority(x, express.top())){
                express.push(s[i]); 
            }
            else{
                while(true){
                    if(express.empty() || express.top() == '(' || Priority(x, express.top())) break;
                    postfix = postfix + express.top();
                    express.pop();
                }
                express.push(x);
            }
        }
        else if(IsCloseBracket(x)){
            if(IsOpenBracket(express.top()))
                express.pop();
            else{
                while(!express.empty() && !IsOpenBracket(express.top())){
                    postfix += express.top();
                    express.pop();
                }
                express.pop();
            }
        }
    }
    char p;
    while(!express.empty()){
        p = express.top();
        postfix += p;
        express.pop();
    }
    cout << postfix ;
}

void CalculatorManipulate(char *s){
    stack<char> parenthesis;
    stack<int> operand;
    int countCloseBracket = 0;
    for(int i = 0;i < strlen(s);i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(')
            parenthesis.push(s[i]);
        else if(isalnum(s[i])){
            int a = s[i] - '0';
            operand.push(a);
        }
        if(s[i] == ')')
            countCloseBracket++;
    }
}

int main()
{
    char s[100] = "7+2*(4+3-5*(9-1)*3)/2";
    if(CheckMatch(s)){
        ConvertToPostFix(s);
    }

}