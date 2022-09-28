#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n;
int m;
int Hash(char *s)
{
    int c = 0;
    for(int i = 0 ; i< strlen(s); i ++){
        c = (c*256 + s[i]) % m;
    }
    return c;
}

int main()
{
    scanf("%d", &n);
    scanf("%d", &m);
    char *s;
    for(int i = 0 ; i < n ; i++){
        scanf("%s", &s);
        printf("%d\n",Hash(s));
    }
    
    return 0;
}