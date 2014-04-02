#include<iostream>

using namespace std;

void COMPUTE_TRANSITION_FUNCTION(char P[],int M,int delta[][26])
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

            for(j=0;j<q;j++)
                s2+=P[j];
            s2+=i+'a';
            s2_len=s2.length();

            for(j=0;j<k;j++)
                s1+=P[j];
            s1_len=s1.length();

            while(true)
            {
                s1_len--;
                flag=true;

                for(j=1;j<=s1_len;j++)
                    if(s1[s1_len-j]!=s2[s2_len-j])
                        flag=false;

                if(flag || s1_len==0)
                    break;
            }
            delta[q][i]=s1_len;
        }
    }
}

void  Finite_Automata_Matcher(char P[],int M,char Q[],int N)
{
    int delta[M+1][26];
    COMPUTE_TRANSITION_FUNCTION(P,M,delta);

    int q=0;
    for(int i=0;i<N;i++)
    {
        q=delta[q][Q[i]-'a'];
        if(q==M)
            cout<<"Found  "<<(i-M+1)<<endl;
    }
}

int main()
{
    int i,M,N;
    char P[100],Q[100];

    cin>>M>>P;
    cin>>N>>Q;

    Finite_Automata_Matcher(P,M,Q,N);

    return 0;
}
/*
7
ababaca
11
abababacaba
*/
