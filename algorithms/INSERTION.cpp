#include<iostream>

using namespace std;

void INSERTION_SORT(int A[],int N)
{
    int i,j,key;
    for(i=1;i<N;i++)
    {
        j=i-1;
        key=A[i];
        while(j>=0 && A[j]>key)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}

int main()
{
    int A[100],i=0,k;

    cin>>k;
    while(k!=-1)
    {
        A[i++]=k;
        cin>>k;
    }

    INSERTION_SORT(A,i);

    for(k=0;k<i;k++)
        cout<<A[k]<<" ";
    cout<<endl;
    return 0;
}

