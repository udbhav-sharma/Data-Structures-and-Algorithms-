#include<iostream>
#include<cmath>

using namespace std;

void RABIN_KARP(int P[],int Q[],int M,int N)
{
    int i,s,p=0,t=0;
    int d=10;
    int q=13;
    int h=1;
    bool check;

    for(i=1;i<M;i++)
        h=h*10;

    for(i=0;i<M;i++)
    {
        p=p*d+P[i];
        t=t*d+Q[i];
    }

    for(s=0;s<=N-M;s++)
    {
        cout<<"t = "<<t<<endl;
        if(p==t)
        {
            check=true;
            for(i=0;i<M;i++)
                if(P[i]!=Q[s+i])
                    check=false;
            if(check)
                cout<<"Found with s = "<<s<<endl;
        }
        t=d*(t-h*Q[s])+Q[s+M];
    }
}

int main()
{
    int P[100],Q[100];
    int i,M,N;

    cin>>M;
    for(i=0;i<M;i++)
        cin>>P[i];

    cin>>N;
    for(i=0;i<N;i++)
        cin>>Q[i];

    RABIN_KARP(P,Q,M,N);

    return 0;
}

/*
5
3 1 4 1 5
19
2 3 5 9 0 2 3 1 4 1 5 2 6 7 3 9 9 2 1
*/
