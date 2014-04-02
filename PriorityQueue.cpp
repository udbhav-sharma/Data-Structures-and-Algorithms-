#include<iostream>
#include<stdio.h>

using namespace std;

int temp[100],size=0;

void IncreaseKey(int x,int k)
{
    if(k<temp[x])
        printf("Error: New key is smaller than Current key\n");
    else
    {
        temp[x]=k;
        while(x>1 && temp[x/2]<temp[x])
        {
            swap(temp[x/2],temp[x]);
            x=x/2;
        }
    }
}

void Insert(int x)
{
    size++;
    temp[size]=-9999;
    IncreaseKey(size,x);
}

int Maximum()
{
    return temp[1];
}

void MaxHeapify(int i)
{
    int largest,left,right;
    left=2*i+1;
    right=2*i+2;
    if(left<size && temp[left]>temp[i])
        largest=left;
    else
        largest=i;
    if(right<size && temp[right]>temp[largest])
        largest=right;
    if(largest!=i)
    {
        swap(temp[largest],temp[i]);
        MaxHeapify(largest);
    }
}

int ExtractMaximum()
{
    swap(temp[1],temp[size]);
    size--;
    MaxHeapify(1);
    return temp[size+1];
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t!=0)
    {
        scanf("%d",&t);
        Insert(t);
    }
    for(t=0;t<size;t++)
        printf("%d ",temp[t]);
    printf("\n");
    return 0;
}
