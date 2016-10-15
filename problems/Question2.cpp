
/* Given an unlimited supply of coins of denominations C1,C2,...,CN we wish to make change for a 
value V. Give ab algorithm for prdoucing change with minimum number of coins. Print denominations 
selected */

#include <set>
#include <iostream>

#define infinity 100007
#define maxn 1000

using namespace std;

struct abc
{
	set<int> p;
};

int N,V;
int W[maxn];
int M[maxn][maxn];
abc Path[maxn][maxn];

int main()
{
	
	for(int i=0;i<maxn;i++)
		for(int j=0;j<maxn;j++)
			M[i][j]=infinity;

	for(int j=0;j<maxn;j++)
		M[0][j]=0;

	cout<<"Enter N:\t";
	cin>>N;
	cout<<"Coins:\n";
	for(int i=1;i<=N;i++)
		cin>>W[i];
	cout<<"Money:\n";
	cin>>V;

	for(int i=1;i<=V;i++)
		for(int j=1;j<=N;j++)
		{
			if(i>=W[j] && (M[i][j-1]>M[i-W[j]][j-1]+1))
			{	
				M[i][j]=M[i-W[j]][j-1]+1;
				Path[i][j].p=Path[i-W[j]][j-1].p;
				Path[i][j].p.insert(W[j]);
			}
			else
			{
				M[i][j]=M[i][j-1];
				Path[i][j].p=Path[i][j-1].p;
			}
		}

	cout<<"No of coins:\t"<<M[V][N]<<endl;

	set<int>::iterator it;
	cout<<"Path:\n";
	for(it=Path[V][N].p.begin();it!=Path[V][N].p.end();it++)
		cout<<*it<<" ";
	cout<<endl;

	return 0;
}