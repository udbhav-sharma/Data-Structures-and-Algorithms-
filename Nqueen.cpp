#include <iostream>
#include <cstring>
#include <cmath>

#define maxn 1000

using namespace std;

int N;
int queen[maxn];

void print_sol()
{
	for(int i=0;i<N;i++)
		cout<<"Queen "<<i+1<<" position:-\t"<<queen[i]+1<<endl;
}

bool isSafe(int i,int j)
{
	for(int k=0;k<i;k++)
	{
		if(abs(queen[k]-j)==abs(k-i))
			return false;
		if(queen[k]==j)
			return false;		
	}
	return true;
}

bool solveNQueen(int i)
{
	if(i==N)
		return true;
	for(int j=0;j<N;j++)
	{
		if(isSafe(i,j))
		{
			queen[i]=j;
			if(solveNQueen(i+1))
				return true;
			queen[i]=-1;
		}
	}
	return false;
}

int main()
{
	cout<<"Enter N:\t";
	cin>>N;
	
	memset(queen,-1,sizeof(queen));

	if(!solveNQueen(0))
		cout<<"No solution exists\n";
	else
		print_sol();
	
	return 0;
}
