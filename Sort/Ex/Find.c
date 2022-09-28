#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000000

int A[MAX];
int n,m, count = 0;
int Temp[MAX/2+1];
void Merge(int head, int mid, int tail)
{
    int head1 = head;
    int tail1 = mid;
    int head2 = mid + 1;
    int tail2 = tail;
    int index = head1;
    for( ; (head1 <= tail1) && (head2 <= tail2) ; index++){
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

int BinarySearch(int head,int tail, int value)
{
    if(tail >= head){
        int mid = (head + tail)/2;
        if(A[mid] == value) return mid;
        if(A[mid] > value)
            return BinarySearch(head,mid-1,value);
        return BinarySearch(mid+1,tail,value);
    }
    return -1;
}

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
    MergeSort(0,n-1);
    // for(int i=0;i<n;i++)
    //     printf("%d\t",A[i]);
    for(int i=0;i<n;i++){
        int b = m - A[i];
        if(BinarySearch(0,n-1,b) != -1 && BinarySearch(0,n-1,b) > i)
            count++;
    }
    printf("%d",count);
}

//Way 2
// int sum[1000000];
// int main()
// {
//     scanf("%d",&n);
//     scanf("%d",&m);
//     for(int i = 0;i < n;i++){
//         scanf("%d",&A[i]);
//     }
//     memset(sum,0,sizeof(sum));
//     int count = 0;
//     for(int i = 0;i < n;i++){
//         if(sum[A[i]] != 0) 
//             count++;
//         else
//             sum[m-A[i]] = 1;
//     }
//     printf("%d",count);
// }