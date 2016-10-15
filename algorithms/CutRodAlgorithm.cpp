#include <iostream>
#include <stdio.h>

#define infinity 1<<30

using namespace std;

void CutOfRod(int P[],int S[],int R[],int N)
{
    int i,j,temp;
    R[0]=0;
    S[0]=0;
    for(i=1;i<=N;i++)
    {
        temp=-infinity;
        for(j=1;j<=i;j++)
        {
            if(temp<P[j]+R[i-j])
            {
                temp=P[j]+R[i-j];
                S[i]=j;
            }
            R[i]=temp;
        }
    }
}

void PrintCutOfRod(int S[],int N)
{
    int i,j;
    for(i=1;i<=N;i++)
    {
        j=i;
        while(j>0)
        {
            cout<<S[j]<<" ";
            j-=S[j];
        }
        cout<<endl;
    }
}

int main()
{
    int N,i;
    cin>>N;
    int P[N+1],S[N+1],R[N+1];
    P[0]=0;

    for(i=1;i<=N;i++)
        cin>>P[i];

    CutOfRod(P,S,R,N);
    PrintCutOfRod(S,N);

    return 0;
}
