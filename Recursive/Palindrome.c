#include<stdio.h>
#include<string.h>

int Palindrome(char s[], int start, int end)
{
    if(start >= end)
        return 1;
    else{
        return (s[start] == s[end] && Palindrome(s,start+1,end-1));
    }
}

int main()
{
    char s[20];
    printf("Enter string : ");
    scanf("%s",&s);
    int end = strlen(s);
    if(Palindrome(s,0,end-1))
        printf("This string is a palindrome");
    else
        printf("This string is not a palindrome");
}