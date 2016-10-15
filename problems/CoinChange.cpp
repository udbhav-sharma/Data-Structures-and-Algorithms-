#include <iostream>

#define infinity 100007
#define MAXN 10000
#define MAXM 1000

using namespace std;

int N;
int Distance[MAXN+1][MAXM];
int Array[MAXM];

int main()
{
	int i,j,N,M;

	cout<<"Total Array inputs:\t";
	cin>>M;

	cout<<"Array inputs:\n";
	for(i=0;i<M;i++)
		cin>>Array[i];

	cout<<"Number to be formed:\t";
	cin>>N;

	for(i=0;i<M;i++)
		Distance[0][i]=1;

	int X,Y;
	
	for(i=1;i<=N;i++)
		for(j=0;j<M;j++)
		{
			X= (i-Array[j]>=0) ? Distance[i-Array[j]][j] : 0;
			Y= (j >= 1)? Distance[i][j-1]: 0; 
			Distance[i][j]=X+Y;
		}
	cout<<Distance[N][M-1]<<endl;
	return 0;
}