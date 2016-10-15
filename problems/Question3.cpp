/*
	To find the sum of contiguous subarray within a one-dimensional array of numbers 
	which has the largest sum. Kadane's Alogrithm
*/

#include <iostream>
#define maxn 100005
#define infinity 100007

using namespace std;

int input[maxn];

int main()
{
	int N;
	cout<<"Enter N:\t";
	cin>>N;

	for(int i=0;i<N;i++)
		cin>>input[i];

	int max=input[0];
	int sum=input[0];
	for(int i=1;i<N;i++)
	{
		sum+=input[i];
		if(sum<0)
			sum=0;
		if(sum>max)
			max=sum;
	}
	cout<<max<<endl;
	return 0;
}