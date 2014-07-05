#include <time.h>
#include <iostream>
#include <stdlib.h>

#define maxn 1000

using namespace std;

int Numbers[maxn];

int parition(int i,int j)
{
	int m=i-1;
	for(int k=i;k<j;k++)
	{
		if(Numbers[k]<Numbers[j])
		{
			m++;
			swap(Numbers[m],Numbers[k]);
		}
	}
	swap(Numbers[m+1],Numbers[j]);
	return m+1;
}

int Random_partition(int i,int j)
{
	int k=(rand()%(j-i))+i;
	swap(Numbers[j],Numbers[k]);
	return parition(i,j);
}

int FindElement(int i,int j,int k)
{
	if(i==j)
		return Numbers[i];
	int q=Random_partition(i,j);
	if(k==q)
		return Numbers[q];
	if(k<q)
		return FindElement(i,q-1,k);
	else
		return FindElement(q+1,j,k);
}

int main()
{
	srand (time(NULL));
	int i,k,n=0;
	cout<<"Enter elements -1 to end input\n";
	while(true)
	{
		cin>>i;
		if(i==-1)
			break;
		Numbers[n++]=i;
	}

	while(true)
	{
		cout<<"Enter K:\t";
		cin>>k;
		if(k==-1)
		{
			cout<<"Done\n";
			break;
		}
		cout<<"Element is:\t"<<FindElement(0,n-1,k-1)<<endl;
	}
	return 0;
}
