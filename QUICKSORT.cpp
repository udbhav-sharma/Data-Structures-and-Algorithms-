#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int Partition(int A[],int p,int r)
{
    int x=A[r];
    int i=p-1;
    int j;

    for(j=p;j<r;j++)
        if(A[j]<=x)
            swap(A[++i],A[j]);
    swap(A[++i],A[r]);
    return i;
}

int Random_partition(int A[],int i,int j)
{
	int k=(rand()%(j-i+1))+i;
	swap(A[j],A[k]);
	return Partition(A,i,j);
}

void QuickSort(int A[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=Random_partition(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}

int main()
{
    srand (time(NULL));
    int T,N,i;
    int A[100];

    cout<<"Enter the number of test cases:\n";
    cin>>T;

    while(T--)
    {
        cout<<"Enter the size of the array:\n";
        cin>>N;

        cout<<"Enter the elements:\n";
        for(i=0;i<N;i++)
            cin>>A[i];

        QuickSort(A,0,N-1);

        for(i=0;i<N;i++)
            cout<<A[i]<<" ";
        cout<<endl;
    }
    return 0;
}
