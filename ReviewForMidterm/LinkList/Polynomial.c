#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Element{
    int coefficient;
    int exponent;
    struct Element* next;
}Element;

typedef struct Polynomial{
    int id;
    Element* element;
    struct Polynomial* next;
}Polynomial;

Polynomial *head, *tail;

Polynomial* CreatePolynomial(int id)
{
    Polynomial* p = (Polynomial*)malloc(sizeof(Polynomial));
    p->id = id;
    p->element = NULL;
    p->next = NULL;
    return p;
}

Element *CreateElement(int coef, int exp)
{
    Element *e = (Element*)malloc(sizeof(Element));
    e->coefficient = coef;
    e->exponent = exp;
    e->next = NULL;
    return e;
}

Element *AddElement(Element *head, int coef, int exp)
{
    Element *e = CreateElement(coef, exp);
    if(head == NULL){
        head = e;
    }else{
        Element *last = head; 
        while (last->next != NULL) 
            last = last->next; 
        last->next = e;
    }
    return head;
}

int EmptyPolynomial()
{
    return head == NULL && tail == NULL;
}

void CREATE(int id)
{
    Polynomial *p = CreatePolynomial(id);
    if(EmptyPolynomial()){
        head  = p;
        tail = p;
    }else{
        tail->next = p;
        tail = p; 
    }
}

void ADDTERM(int id, int coef, int exp)
{
    for(Polynomial *cur = head; cur != NULL; cur = cur->next){
        if(cur->id == id){
            cur->element = AddElement(cur->element,coef,exp);
            break;
        }
    }
}

void SHOW(int id)
{
    for(Polynomial *cur = head; cur != NULL; cur = cur->next){
        printf("\t\t\t\t");
        if(cur->id == id){
            for(Element *present = cur->element; present != NULL; present = present->next){
                if(present->next != NULL){
                    printf("%d.x^%d   +    ",present->coefficient,present->exponent);
                }
                else    printf("%d.x^%d",present->coefficient,present->exponent);
            }
            break;
        }    
    }
    printf("\n");
}

int main()
{
    char cmd[20];
    char require[20];
    int id, coef, exp;
    do{
        printf("\tEnter command : ");
        scanf("%s",&cmd);
        if(strcmp(cmd,"Create") == 0){
            printf("\t\tEnter id to create : ");
            scanf("%d",&id);
            CREATE(id);
        }
        if(strcmp(cmd,"Addterm") == 0){
            printf("\t\tEnter id to add : ");
            scanf("%d",&id);
            printf("\t\tEnter coefficient : ");
            scanf("%d",&coef);
            printf("\t\tEnter exponent : ");
            scanf("%d",&exp);
            ADDTERM(id,coef,exp);
        }
        if(strcmp(cmd,"Show") == 0){
            printf("\t\tEnter id to show : ");
            scanf("%d",&id);
            SHOW(id);
        }
    }while(strcmp(cmd,"Exit") != 0);

    // CREATE(1);
    // ADDTERM(1,2,3);
    // ADDTERM(1,6,4);
    // ADDTERM(1,7,2);
    // CREATE(2);
    // ADDTERM(2,3,4);
    // ADDTERM(2,6,7);
    // SHOW(1);
    // SHOW(2);
}