#include <iostream>

#define infinity 1000007
#define MAXN 100
#define MAXK 10000

using namespace std;

int E[MAXK][MAXN];

int main()
{
	int N,K;
	cout<<"Eggs: \t";
	cin>>N;
	cout<<"Floors: \t";
	cin>>K;

	for(int i=0;i<=N;i++)
	{
		E[0][i]=0;
		E[1][i]=1;
	}

	for(int i=0;i<=K;i++)
		E[i][1]=i;

	for(int j=2;j<=N;j++)
		for(int i=2;i<=K;i++)
		{
			E[i][j]=infinity;
			for(int t=1;t<=i;t++)
				E[i][j]=min(E[i][j],1+max(E[t-1][j-1], E[i-t][j])); 
		}

	cout<<E[K][N]<<endl;
	return 0;
}