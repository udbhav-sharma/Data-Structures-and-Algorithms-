#include<iostream>

using namespace std;

void COMPUTE_PREFIX_FUNCTION(char P[],int M,int pie[])
{
    pie[0]=-1;
    int k=-1,q;

    for(q=1;q<M;q++)
    {
        while(k>=0 && P[k+1]!=P[q])
            k=pie[k];
        if(P[k+1]==P[q])
            k=k+1;
        pie[q]=k;
    }
}

void KMP_MATCHER(char P[],int M,char Q[],int N)
{
    int pie[M],i,q=-1;

    COMPUTE_PREFIX_FUNCTION(P,M,pie);

    for(i=0;i<N;i++)
    {
        while(q>=0 && P[q+1]!=Q[i])
            q=pie[q];
        if(P[q+1]==Q[i])
            q++;
        if(q==M-1)
            cout<<"Found  "<<i-M+1<<endl;
    }
}

int main()
{
    int M,N;
    char P[100],Q[100];

    cin>>M>>P;
    cin>>N>>Q;

    KMP_MATCHER(P,M,Q,N);

    return 0;
}
