#include<iostream>
#include<stdio.h>
using namespace std;
void MaxHeapify(int temp[],int i,int n)
{
    int largest,left,right;
    left=2*i+1;
    right=2*i+2;
    if(left<n && temp[left]>temp[i])
        largest=left;
    else
        largest=i;
    if(right<n && temp[right]>temp[largest])
        largest=right;
    if(largest!=i)
    {
        swap(temp[largest],temp[i]);
        MaxHeapify(temp,largest,n);
    }
}
void BuildMaxHeap(int temp[],int n)
{
    int i;
    for(i=n/2;i>=0;i--)
        MaxHeapify(temp,i,n);
}
void HeapSort(int temp[],int n)
{
    int i;
    BuildMaxHeap(temp,n);
    for(i=n-1;i>0;i--)
    {
        swap(temp[i],temp[0]);
        n--;
        MaxHeapify(temp,0,n);
    }
}
int main()
{
    int i,n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int a[n];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        HeapSort(a,n);
        for(i=0;i<n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}
