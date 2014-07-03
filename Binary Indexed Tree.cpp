#include <cstring>
#include <iostream>
#define maxn 100005

using namespace std;

int BIT[maxn];

void Initialize()
{
    memset(BIT,0,sizeof(BIT));
}

void UpdateBIT(int n,int f)
{
    while(n<maxn)
    {
        BIT[n]+=f;
        n+=n&(-n);
    }
}

int QueryBIT(int n)
{
    int sum=0;
    while(n>0)
    {
        sum+=BIT[n];
        n-=n&(-n);
    }
    return sum;
}

int main()
{
    int n,f;
    Initialize();
    cout<<"Input Number Frequency:\n";
    cin>>n;
    while(n!=-1)
    {
        cin>>f;
        UpdateBIT(n,f);
        cin>>n;
    }
    cout<<"Query:\n";
    int i,j;
    cin>>i;
    while(i!=-1)
    {
        cin>>j;
        cout<<(QueryBIT(j)-QueryBIT(i-1))<<endl;
        cin>>i;
    }
    return 0;
}
