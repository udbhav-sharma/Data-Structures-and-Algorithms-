#include <iostream>

#define maxn 1001
#define maxw 1001

using namespace std;

int N,W;
int Values[maxn];
int Weight[maxn];
int M[maxw][maxn];

int main()
{
	cout<<"Number of elements\n";
	cin>>N;
	
	cout<<"Enter the values\n";
	for(int i=1;i<=N;i++)
		cin>>Values[i];

	cout<<"Enter the weights\n";
	for(int i=1;i<=N;i++)
		cin>>Weight[i];
	
	cout<<"Enter Weight\n";
	cin>>W;

	for(int i=0;i<=W;i++)
		M[i][0]=0;

	for(int j=0;j<=N;j++)
		M[0][j]=0;

	for(int j=1;j<=N;j++)
		for(int i=1;i<=W;i++)
			if(Weight[j]<=i)
				M[i][j]=max(M[i][j-1],M[i-Weight[j]][j-1]+Values[j]);

	cout<<M[W][N]<<endl;

	return 0;
}