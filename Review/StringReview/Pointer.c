#include <stdio.h>
#include<string.h>

int main(){
    char str[100];
    char *p;
    p=str;
    scanf("%s",&str);
    printf("%s",p+1);
}