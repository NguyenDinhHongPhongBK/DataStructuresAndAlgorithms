#include<stdio.h>
#include<string.h>
void Delete(char str1[],char str2[], char str3[]){
    int lengthStr2= strlen(str2);
    char str[128] = "";
    char *p1 = str1, *p2;
        
        /* Tạo vòng lặp để xóa hết chuỗi con */
    while((p2 = strstr(p1,str2)) != NULL) { /*Tìm vị trí chuỗi con bằng hàm strstr*/
        printf(",\n--- %d---",p2-p1);
        strncat(str,p1,p2 - p1);   /* Nối các phần không chứa chuỗi con */ 
        strcat(str,str3);
        p1 = p2 + lengthStr2;      /* Dịch chuyển con trỏ sang vị trí tìm kiếm tiếp theo */
    }
    strcat(str,p1);      
    printf("%s",str);
}
int main(){
    char a[20],b[20],c[1000];
    printf("Enter fisrt string : ");
    scanf("%[^\n]%*c",&a);
    printf("Enter second string : ");
    scanf("%[^\n]%*c",&b);
    printf("Enter paragraph : ");
    scanf("%[^\n]%*c",&c);
    Delete(c,a,b);
    
}