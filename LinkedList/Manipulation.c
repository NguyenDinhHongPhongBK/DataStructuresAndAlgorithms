#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int number;
    struct Node* next;
}Node;

Node * CreateNode(int X)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->number = X;
    newNode->next = NULL;
    return newNode;
}

void ShowList(Node *head)
{
    Node *cur = head;
    for(cur = head; cur != NULL; cur = cur->next)
        printf("%d ",cur->number);
}

int CheckAppear(Node *head, int k)
{
    int flag=0;
    if(head == NULL){
        return 0;
    }
    else{
        for(Node *cur = head; cur != NULL; cur = cur->next){
            if(cur->number == k){
                flag = 1;break;
            }
        }
        if(flag == 1)
            return 1;
        else    
            return 0;
    }
}

Node *AddLast(Node *head, int X)
{
    if(CheckAppear(head,X) == 0){
        Node *newNode = CreateNode(X);
        if(head == NULL) 
            head = newNode;
        else{
            Node *last = head;
            while(last->next != NULL)
                last = last->next;
            last->next = newNode;
        }
    }
    return head;
}
Node *AddFirst(Node *head, int X)
{
    if(CheckAppear(head,X) == 0){
        Node *newNode = CreateNode(X);
        if(head == NULL) 
            head = newNode;
        else{
            newNode->next = head;
            head = newNode;
        }
    }
        return head;
}

Node *AddAfter(Node *head, int u, int v)
{
    if(CheckAppear(head,u) == 0 && CheckAppear(head,v) == 1)
    {
        Node *newNode = CreateNode(u);
        Node *cur = head;
        for(cur = head; cur != NULL; cur = cur->next){
            if(cur->number == v){
                newNode->next = cur->next;
                cur->next = newNode;
            }
        }
    }
    return head;
}

Node *AddBefore(Node *head, int u, int v)
{
    if(CheckAppear(head,u) == 0 && CheckAppear(head,v) == 1){

        Node *newNode = CreateNode(u);
        Node *cur = head;
        for(cur = head; cur != NULL; cur = cur->next){
            if(cur->number == v){
                if(cur == head){
                    head = newNode;
                    newNode->next = cur;
                }
                else{
                    Node *prev = head;
                    while(prev->next != cur)
                        prev = prev->next;
                    prev->next = newNode;
                    newNode->next = cur;
                }
            }
        }
    }
        return head;
}

Node *Remove(Node *head, int k)
{
    Node *cur = head;
    Node *prev = NULL;
    if(head == NULL) return NULL;
    while(cur->number != k){
        prev = cur;
        cur = cur->next;
    }
    if(cur == head){
        head = cur->next;
        free(cur);
    }
    else{
        prev->next = cur->next;
        free(cur);
    }
    return head;
}

Node* Reverse(Node* head)
{
    Node *cur = head;
    Node *prev = NULL;
    Node *after;
    while(cur != NULL){
        after = cur->next;
        cur->next = prev;
        prev=cur;
        cur=after;
    }
    head = prev;
    return head;
}


int main(){
    struct Node* head = NULL;
    int n,add,delete,key;
    char cmd[20];
    // printf("Enter number of elements in linked list : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int value;
        // printf("Enter value for node %d : ",i+1);
        scanf("%d",&value);
        head = AddLast(head,value);
    }

    // ShowList(head);

    do{
        // printf("\nEnter command : ");
        scanf("%s",&cmd);
        if(strcmp(cmd,"addlast") == 0){
            // printf("Enter number to add : ");
            scanf("%d",&add);
            head = AddLast(head,add);
            // ShowList(head);
        }
        else if(strcmp(cmd,"addfirst") == 0){
            // printf("Enter number to add : ");
            scanf("%d",&add);
            head = AddFirst(head,add);
            // ShowList(head);
        }
        else if(strcmp(cmd,"addafter") == 0){
            // printf("Enter number to add : ");
            scanf("%d",&add);
            // printf("Enter value to compare : ");
            scanf("%d",&key);
            head = AddAfter(head,add,key);
            // ShowList(head);
        }
        else if(strcmp(cmd,"addbefore") == 0){
            // printf("Enter number to add : ");
            scanf("%d",&add);
            // printf("Enter value to compare : ");
            scanf("%d",&key);
            AddBefore(head,add,key);
            // ShowList(head);
        }
        else if(strcmp(cmd,"remove") == 0){
            // printf("Enter number to remove : ");
            scanf("%d",&delete);
            head = Remove(head,delete);
            // ShowList(head);

        }
        else if(strcmp(cmd,"reverse" )== 0){
            head = Reverse(head);
            // ShowList(head);

        }

    }while(strcmp(cmd,"#") != 0);

    ShowList(head);
}