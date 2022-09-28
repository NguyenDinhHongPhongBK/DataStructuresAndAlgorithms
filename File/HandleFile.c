#include<stdio.h>
#include<string.h>

typedef struct Vehicle{
    char name[20];
    double price;
}Vehicle;

void CreateFile(char file[]){
    printf("Enter filename : ");
    scanf("%s", file);
    FILE *f = fopen(file,"wb");
    fclose(f);
}

void WriteData(char file[]){
    printf("Enter filename : ");
    scanf("%s", file);
    Vehicle v;
    FILE* f=fopen(file,"w");
    if(f==NULL){
        printf("Cannot open this file %s for appending \n",file);
    }else{
        printf("Enter name : ");
        scanf("%s", &v.name);
        printf("Enter price : ");
        scanf("%d", &v.price);
        fwrite(&v,sizeof(Vehicle),1,f);
        
    }
    
}

void ReadData(char file[]){
    printf("Enter filename : ");
    scanf("%s", file);
}


int main ()
{
    FILE *fp;
    char file[100];
    char cmd[100];
    while(1){
        printf("Enter command : ");
        scanf("%s",cmd);
        if(strcmp(cmd,"q")==0)
            break;
        else if (strcmp(cmd,"create")==0)
            CreateFile(file);
        else if(strcmp(cmd,"write")==0)
            WriteData(file);
        
    }
    
}