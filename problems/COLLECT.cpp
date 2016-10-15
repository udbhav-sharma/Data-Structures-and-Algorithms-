#include<iostream>
#include<stdio.h>
#include<cstring>
#define Mod 3046201

using namespace std;

int tree[100005];
int input[100005];
long long fact[3000005];

int read(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=(idx & -idx);
    }
    return sum;
}

void update(int idx,int val,int Maxval)
{
    while(idx<=Maxval)
    {
        tree[idx]+=val;
        idx+=(idx & -idx);
    }
}

long long repeated_squaring(long long n,int p)
{
	if(p==0)
        return 1;
    else if(p==1)
        return n;
    else if (p%2!=0)
        return (n*repeated_squaring((n*n)%Mod,(p-1)/2))%Mod;
    else
        return repeated_squaring((n*n)%Mod,p/2)%Mod;
}

int main()
{
    int N,Q,i,j,B,T,K,A,D;
    long long numerator,denominator,combination,permutation,ans;
    char cmd[10];

    scanf("%d",&N);

    memset(tree,0,sizeof(tree));

    fact[0]=1;
    for(i=1;i<=3000004;i++)
    {
        fact[i]=(fact[i-1]*(long long)i)%Mod;
    }

    for(i=1;i<=N;i++)
    {
        scanf("%d",&input[i]);
        update(i,input[i],N);
    }

    scanf("%d",&Q);

    while(Q--)
    {

        scanf("%s",cmd);

        if(cmd[0]=='c')
        {
            scanf("%d%d",&i,&j);
            update(i,j-input[i],N);
            input[i]=j;
        }
        else
        {
            scanf("%d%d",&i,&j);

            B=read(j)-read(i-1);
            T=j-i+1;
            K=B%T;
            A=B/T;
            D=A+1;

            if(K!=0)
            {
                numerator=fact[B];
                denominator=(repeated_squaring(fact[D],K)*repeated_squaring(fact[A],T-K))%Mod;

                combination=(numerator*repeated_squaring(denominator,Mod-2))%Mod;
                permutation=(fact[T]*repeated_squaring((fact[K]*fact[T-K])%Mod,Mod-2))%Mod;

                ans=(combination*permutation)%Mod;
                printf("%lld\n",ans);
            }

            else
            {
                numerator=fact[B];
                denominator=repeated_squaring(fact[A],T);
                ans=(numerator*repeated_squaring(denominator,Mod-2))%Mod;
                printf("%lld\n",ans);
            }
        }
    }

    return 0;
}
