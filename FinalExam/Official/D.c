#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define M 100007

int number_transactions = 0;
int total_money_transactions = 0;
int Arr[100],x[100], n,results = 0;
char acc[100];

int Hash(char *s)
{
    int c = 0;
    for(int i = 0 ; i< strlen(s); i ++){
        c = (c*256 + s[i]) % M;
    }
    return c;
}

typedef struct Tree{
    char account[100];
    struct Tree *left;
    struct Tree *right;
}Tree;
Tree *root;

Tree *Create(char *account)
{
    Tree *tr = (Tree *)malloc(sizeof(Tree));
    strcpy(tr->account, account);
    tr->left = NULL;
    tr->right = NULL;
    return tr;
}

Tree *Find(char *account,Tree *root){
    if(root == NULL) return NULL;
    int c = strcmp(root->account,account);
    if(c == 0) return root;
    if(c < 0)
        return Find(account,root->right);
    else
        return Find(account,root->left);

}

Tree *Insert(Tree *root,char *account){
    if(root == NULL) 
        root = Create(account);
    int a = strcmp(root->account,account);
    if(a == 0)
        return root;
    if(a > 0)
        root->left = Insert(root->left,account);
    else
        root->right = Insert(root->right,account);
    return root;
}

void InOrder(Tree *root)
{
    if(root == NULL) return;
    InOrder(root->left);
    printf("%s ",root->account);
    InOrder(root->right);
}

typedef struct Node{
    char account[100];
    struct Node *next;
}Node;

Node *CreateList(char *account)
{
    Node *p = (Node *)malloc(sizeof(Node));
    strcpy(p->account,account);
    p->next = NULL;
    return p;
}

int CheckAppear(char *account, Node *head)
{
    Node *cur = head;
    if(cur == NULL)
        return 0;
    while(cur != NULL){
        if(strcmp(cur->account,account) == 0)
            return 1;
        cur = cur->next;
    }
    return 0;
}

Node* InsertHead(char *account, Node*head)
{
    if(CheckAppear(account,head) == 1) return NULL;
    Node *p = CreateList(account);
    if(head == NULL){
        head = p;
    }
    else{
        p->next = head;
        head = p;
    }
    return head;
}
typedef struct Send{
    char send_account[100];
    Node* receive_account;
    int money;
    struct Send* left;
    struct Send* right;
}Send;

Send *ArrSend[100000];

Send *CreateSend(char *account,char*receive,int money)
{
    Send *s = (Send *)malloc(sizeof(Send));
    strcpy(s->send_account,account);
    Node*head = CreateList(receive);
    s->receive_account =head;
    s->money = money;
    s->left = NULL;
    s->right = NULL;
    return s;
}

Send *FindFromTree(char *account,Send *root){
    if(root == NULL) return NULL;
    int c = strcmp(root->send_account,account);
    if(c == 0) return root;
    if(c < 0)
        return FindFromTree(account,root->right);
    else
        return FindFromTree(account,root->left);

}

Send* InsertToTree(Send *root, char *account,char *receive,int money)
{
    if(root == NULL) 
        root = CreateSend(account,receive,money);
    int a = strcmp(root->send_account,account);
    if(a == 0)
        return root;
    if(a > 0)
        root->left = InsertToTree(root->left,account,receive,money);
    else
        root->right = InsertToTree(root->right,account,receive,money);
    return root;
}

Send*FIND(char *account)
{
    int hash = Hash(account);
    if(ArrSend[hash] == NULL) return NULL;
    Send *f = FindFromTree(account,ArrSend[hash]);
    return f;
}

Node *list[10000];

int check(int k,Send *s,Node *cur){
    // Node *no = s->receive_account;
    // if(no == NULL) return 0;
    if(FIND(cur->account) == NULL) return 0;
    if(k < n){
        // for( int i = 2;i < k;i++){
        //     if(strcmp(list[1]->account,list[i]->account) == 0)
        //         return 0;
        // }
        if(strcmp(acc,cur->account) == 0) 
            return 0;
    }
    if(k>1){
        if(strcmp(cur->account,list[k-1]->account) == 0)
            return 0;
    }
    return 1;
}
void Try(int k,Send *s)
{
    for(Node *cur = s->receive_account;cur != NULL;cur = cur->next){
        if(check(k,s,cur)){
            list[k] = cur;
            if(k ==n){
                if(strcmp(list[n]->account,acc) == 0){
                    results = 1;
                }
            }else{
                Send *send = FIND(cur->account);
                Try(k+1,send);
            }
        }
    }
}

int main()
{
    char cmd[100];
    char from_account[100];
    char to_account[100];
    int money;
    char time_point[12];
    char atm[20];
    while(1){
        scanf("%s",from_account);
        if(strcmp(from_account,"#") == 0) break;
        scanf("%s",to_account);
        scanf("%d",&money);
        scanf("%s",time_point);
        scanf("%s",atm);

        if(Find(to_account,root) == NULL)
            root = Insert(root,to_account);
        if(Find(from_account,root) == NULL)
            root = Insert(root,from_account);

        int hash = Hash(from_account);
        Send *s = FIND(from_account);
        if(s == NULL){
            ArrSend[hash] = InsertToTree(ArrSend[hash],from_account,to_account,money);
        }
        else{
            s->receive_account = InsertHead(to_account,s->receive_account);
            s->money +=money;
        }
        number_transactions++;
        total_money_transactions+=money;
    }
    while(1){
        scanf("%s",&cmd);
        if(strcmp(cmd, "#") == 0) break;
        if(strcmp(cmd,"?number_transactions") == 0){
            printf("%d\n",number_transactions);
        }
        if(strcmp(cmd,"?total_money_transaction") == 0){
            printf("%d\n",total_money_transactions);
        }
        if(strcmp(cmd,"?list_sorted_accounts") == 0){
            InOrder(root);
        }
        if(strcmp(cmd,"?total_money_transaction_from") == 0){
            char account[100];
            scanf("%s",account);
            Send *se = FIND(account);
            if(se == NULL)
                printf("%d\n",0);
            else
                printf("%d\n",se->money);
        }
        if(strcmp(cmd,"?inspect_cycle") == 0){
            scanf("%s",acc);
            scanf("%d",&n);
            for(int i = 0;i<100;i++){
                Arr[i] = 0;
            }
            Send*s = FIND(acc);
            if(s == NULL)
                printf("%d\n",0);
            else{
                Try(1,s);
                printf("%d\n",results);
                results = 0;
            }
        }
    }
}