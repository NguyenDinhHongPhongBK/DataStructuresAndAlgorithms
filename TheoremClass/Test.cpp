#include<iostream>
#include<string.h>
#include<ctype.h>
#include<stack>
using namespace std;

void AddLast(char *s,char x)
{
    int j = strlen(s);
    s[j] = x;
}

bool IsOperand(char x)
{
    if(isalnum(x) )
        return true;
    return false;
}

bool IsOperator(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
        return true;
    return false;
}

int main()
{
    char *s;
    char c[100] = "Phong12";
   
    string str;
    str += 'a';


    char ch = ')';

    
    stack<int> st;
    st.push(1);
    st.push(7);
    st.push(9);
    int n = st.top();

    cout << n;
    
    int a = 0;
    while(true){
        a++;
        cout << a;
        if(a > 3) break;
    }


}