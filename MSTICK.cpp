#include<stdio.h>
#include<algorithm>
#define Infinity 1<<30
#define SZ 500002
using namespace std;
int MaxTreeArr[500001];
int MinTreeArr[500001];
int BurnDownTime[100001];

void BuildMaxSegTree(int node,int a,int b)
{
    if(a>b)
                return;// Out of range
        if(a==b) // Leaf node
        {
                MaxTreeArr[node]=BurnDownTime[a];
                return;
        }
        BuildMaxSegTree(2*node,a,(a+b)/2);// Init left child
        BuildMaxSegTree(2*node+1,(a+b)/2+1,b); // Init right child
        MaxTreeArr[node]=max(MaxTreeArr[2*node],MaxTreeArr[2*node+1]);// Init root value
}
void BuildMinSegTree(int node,int a,int b)
{
        if(a>b)
                return;
        if(a==b)
        {
                MinTreeArr[node]=BurnDownTime[a];
                return;
        }
        BuildMinSegTree(2*node,a,(a+b)/2);
        BuildMinSegTree(2*node+1,(a+b)/2+1,b);
        MinTreeArr[node]=min(MinTreeArr[2*node],MinTreeArr[2*node+1]);
}
/**
* Query tree to get min element value within range [i, j]
*/
double ranMinimumQuery(int node,int ss,int se,int qs,int qe)
{
        if(ss>se||ss>qe||se<qs) return Infinity;
        if(ss>=qs&&se<=qe)
                return MinTreeArr[node];
        double q1=ranMinimumQuery(2*node,ss,(ss+se)/2,qs,qe);
        double q2=ranMinimumQuery(2*node+1,(ss+se)/2+1,se,qs,qe);
        double res=min(q1,q2);
        return res;
}
/**
* Query tree to get max element value within range [i, j]
*/
double ranMaximumQuery(int node,int ss,int se,int qs,int qe)
{
        if(ss>se||ss>qe||se<qs) return -Infinity;
        if(ss>=qs&&se<=qe)
                return MaxTreeArr[node];
        double q1=ranMaximumQuery(2*node,ss,(ss+se)/2,qs,qe);
        double q2=ranMaximumQuery(2*node+1,(ss+se)/2+1,se,qs,qe);
        double res=max(q1,q2);
        return res;
}

int main()
{
    int N,i,Q,j;
    double a,b,c,d,ans;
    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%d",&BurnDownTime[i]);
    BuildMaxSegTree(1,0,N-1);
    BuildMinSegTree(1,0,N-1);
    scanf("%d",&Q);
    while(Q--)
    {
        a=0;
        c=0;
        scanf("%d%d",&i,&j);
        b=ranMinimumQuery(1,0,N-1,i,j);
        a=ranMaximumQuery(1,0,N-1,0,i-1);
        d=ranMaximumQuery(1,0,N-1,i,j);
        c=ranMaximumQuery(1,0,N-1,j+1,N-1);
        ans=(d-b)/2.0;
        if(ans<c)
            ans=c;
        if(ans<a)
            ans=a;
        ans+=b;
        printf("%0.1lf\n",ans);
    }
    return 0;
}
