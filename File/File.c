#include<stdio.h>
#include<string.h>
#define MAX_SZ 5

typedef struct ElementType{
    char name[50];
    int age;
}Element;

void executeCreate(char filename[]){
    printf("Input filename : %s", filename);
    scanf("%s",filename);
    FILE* f=fopen(filename,"wb");
    fclose(f);
}

void executeLoad(char filename[]){
    printf("Input filename : %s", filename);scanf("%s",filename);
    FILE* f=fopen(filename,"rb");
    Element buffers[MAX_SZ];
    while(1){
        int sz = fread(buffers, sizeof(Element),MAX_SZ,f);
        for(int i=0;i<sz;i++){
            printf("Name = %s , age = %d ",buffers[i].name,buffers[i].age);
        }
        if(sz<MAX_SZ) break;
    }
    fclose(f);
}

void executeExtend(char filename[]){
    printf("Input filename : %s", filename);scanf("%s",filename);
    Element e;
    FILE* f=fopen(filename,"ab");
    if(f==NULL){
        printf("Cannot open this file %s for appending \n",filename);
    }else{
        printf("Input name : ");scanf("%s",&e.name);
        printf("Input age : ");scanf("%d",&e.age);
        fwrite(&e,sizeof(Element),1,f);
        int sz=fwrite(&e,sizeof(Element),1,f);
        if(sz==1){
            printf("Write Successfully\n");
        }
    }

}

void executeReadAt(char filename[]){
    printf("Input filename : %s", filename);scanf("%s",filename);
    FILE* f=fopen(filename,"rb");
    if(f==NULL){
        printf("Cannot open file for reading");return;
    }
    int i;
    printf("Enter an index : ");scanf("%d",&i);
    fseek(f,sizeof(Element)*i,SEEK_SET);
    Element e;
    fread(&e,sizeof(Element),1,f);
    int sz=fread(&e,sizeof(Element),1,f);
    if(sz==0){
        printf("Cannot read the record at index %d\n",i);
    }
    printf("Read strudent name : %s , age : %d",e.name,e.age);
    fclose(f);

}

int main(){
    char cmd[100];
    char filename[100];
    while(1){
        printf("Input a command : ");scanf("%s",cmd);
        if(strcmp(cmd,"q")==0)
            break;
        else if (strcmp(cmd,"create")==0)
            executeCreate(filename);
        else if(strcmp(cmd,"load-all")==0)
            executeLoad(filename);
        else if(strcmp(cmd,"extend")==0)
            executeExtend(filename);
        else if(strcmp(cmd,"read-at")==0)
            executeReadAt(filename);
        
    }
}