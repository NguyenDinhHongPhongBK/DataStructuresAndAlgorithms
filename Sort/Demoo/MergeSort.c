#include<stdio.h>

#define MAX 1000000

int A[MAX], n;
int Temp[MAX/2+1];
void Merge(int head, int mid, int tail)
{
    int head1 = head;int tail1 = mid;
    int head2 = mid + 1;int tail2 = tail;
    int index = head1;
    for(;(head1 <= tail1) && (head2 <= tail2);index++){
        if(A[head1] < A[head2]){
            Temp[index] = A[head1];
            head1++;
        }
        else{
            Temp[index] = A[head2];
            head2++;
        }
    }
    for( ; head1 <= tail1; head1++,index++)
        Temp[index] = A[head1];
    for( ; head2 <= tail2; head2++,index++)
        Temp[index] = A[head2];
    for(index = head; index <= tail; index++)
        A[index] = Temp[index];
    
}
void MergeSort(int head,int tail)
{
    if(head < tail){
        int mid = (head + tail)/2;
        MergeSort(head,mid);
        MergeSort(mid+1,tail);
        Merge(head,mid,tail);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&A[i]);
    MergeSort(0,n - 1);
    for(int i = 0;i < n;i++)
        printf("%d",A[i]);
}