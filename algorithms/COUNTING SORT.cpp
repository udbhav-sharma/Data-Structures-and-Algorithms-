#include<iostream>

using namespace std;

void COUNTING_SORT(int A[],int B[],int N,int k)
{
    int i;
    int C[k+1];

    for(i=0;i<=k;i++)
        C[i]=0;

    for(i=0;i<N;i++)
        C[A[i]]++;

    for(i=1;i<=k;i++)
        C[i]+=C[i-1];

    for(i=0;i<N;i++)
    {
        B[C[A[i]]-1]=A[i];
        C[A[i]]--;
    }
}

int main()
{
    int k,i=0,j;
    int A[100],B[100];

    cin>>k;
    j=k;
    while(k!=-1)
    {
        A[i++]=k;
        j=max(j,k);
        cin>>k;
    }

    COUNTING_SORT(A,B,i,j);

    for(k=0;k<i;k++)
        cout<<B[k]<<" ";
    cout<<endl;
    return 0;
}
