#include <string>
#include <iostream>

#define maxm 1000

using namespace std;

int delta[maxm+1][26];

void COMPUTE_TRANSITION_FUNCTION(string P,int M)
{
    int q,i,j,k;
    bool flag;
    string s1,s2;
    int s1_len,s2_len;

    for(q=0;q<=M;q++)
    {
        for(i=0;i<26;i++)
        {
            k=min(M+1,q+2);
            s1="";
            s2="";

            s2=P.substr(0,q);
            s2=s2+((char)(i+'a'));
            s2_len=s2.length();

            s1=P.substr(0,k);
            s1_len=s1.length();

            while(true)
            {
                flag=true;

                for(j=1;j<=s1_len;j++)
                    if(s1[s1_len-j]!=s2[s2_len-j])
                        flag=false;

                if(flag || s1_len==0)
                    break;
                s1_len--;
            }
            delta[q][i]=s1_len;
        }
    }
}

void  Finite_Automata_Matcher(string P,int M,string Q,int N)
{
    COMPUTE_TRANSITION_FUNCTION(P,M);

    int q=0;
    for(int i=0;i<N;i++)
    {
        q=delta[q][Q[i]-'a'];
        if(q==M)
            cout<<"Found  "<<(i-M+1)<<endl;
    }
}

void PrintDelta(int M)
{
    cout<<"State\t";
    for(int i=0;i<26;i++)
        cout<<(char)(i+'a')<<"\t";
    cout<<endl;
    for(int i=0;i<=M;i++)
    {
        cout<<i<<"\t";
        for(int j=0;j<26;j++)
            cout<<delta[i][j]<<"\t";
        cout<<endl;
    }
}

int main()
{
    string P,Q;

    cin>>P>>Q;

    Finite_Automata_Matcher(P,P.length(),Q,Q.length());
    //PrintDelta(P.length());
    return 0;
}
/*
ababaca
abababacaba
*/
