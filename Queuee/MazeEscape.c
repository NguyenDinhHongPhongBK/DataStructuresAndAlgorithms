#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Position{
    int row,col;
    int step;
}Position;

typedef struct Node
{
    Position position;
    struct Node* next;
}Node;

Node* head = NULL;
Node* tail = NULL;
int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};
int n,m;
int A[1000][1000];
int startCol,startRow;
int Visited[1000][1000];

int queueEmpty(){
    return head == NULL && tail == NULL;
}

Node *CreateNode(int r, int c,int step)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->position.row = r;
    newNode->position.col = c;
    newNode->position.step = step;
    newNode->next = NULL;
    return newNode;
}

void PushLast(int r, int c, int step) 
{
    Node *newNode = CreateNode(r,c,step);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
}

Position PopHead()
{
    Node* tmp = head;
    Position pos = head->position;
    head = head->next;
    if(head == NULL)
        tail = NULL;
    free(tmp);
    return pos;
}

int FinalPosition(int r, int c){
    return r<1 || r>n || c<1 || c>m;
}

int Check(int r, int c){
    return A[r][c] == 0 && !Visited[r][c];
}

int Solve(){
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            Visited[i][j] = 0;
        }
    }
    PushLast(startRow,startCol,0);
    Visited[startRow][startCol] = 1;

    while(!queueEmpty()){
        Position p = PopHead();
        for(int k=0;k<4;k++){
            int newRow = p.row + dr[k];
            int newCol = p.col + dc[k];
            if(FinalPosition(newRow,newCol)){
                return p.step +1;
            }
            if(Check(newRow,newCol)){
                PushLast(newRow,newCol,p.step+1);
                Visited[newRow][newCol] = 1;
            }
        }
    }
    return -1;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&startRow,&startCol);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&A[i][j]);
        }
    }
}