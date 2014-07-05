#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

void RADIX_SORT(int A[],int N,int d)
{
    int i,j,k;
    queue<int> container[10];
    for(i=0;i<d;i++)
    {
        for(j=0;j<N;j++)
            container[((A[j]/(int)pow(10,i))%10)].push(A[j]);
        for(j=0,k=0;j<10;j++)
        {
            while(!container[j].empty())
            {
                A[k++]=container[j].front();
                container[j].pop();
            }
        }
    }
}

int main()
{
    int i=0,A[100],k,j;

    cin>>k;
    j=k;
    while(k!=-1)
    {
        A[i++]=k;
        cin>>k;
        j=max(j,k);
    }
    k=0;
    while(j!=0)
    {
        j=j/10;
        k++;
    }

    RADIX_SORT(A,i,k);

    for(j=0;j<i;j++)
        cout<<A[j]<<" ";
    cout<<endl;

    return 0;
}
