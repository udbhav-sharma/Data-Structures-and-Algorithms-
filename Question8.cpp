/*
Given a array int a[]={2,5,1,9,3,7,2,8,9,3} and the no. of swap operations.We are allowed to do swap operations. 
swap constraint: exchange only adjacent element. 
Find the max number that can be formed using swap operations.
*/
#include <iostream>
#include <vector>

#define infinity 1000007

using namespace std;

std::vector<int> MaxNumber;

void Maximize(std::vector<int> input,int swaps)
{
	if(input.size()==0)
		return;

	if(swaps==0)
	{
		for(int i=0;i<input.size();i++)
			MaxNumber.push_back(input[i]);
		return;
	}

	int i,max=-infinity,index=-1;
	for(i=0;i<=swaps && i<input.size();i++)
	{
		if(max<input[i])
		{
			max=input[i];
			index=i;
		}
	}

	MaxNumber.push_back(max);
	input.erase(input.begin()+index);
	Maximize(input,swaps-index);
}

int main()
{
	std::vector<int> input;

	cout<<"Elements:\n";
	
	int N;
	cin>>N;

	while(N!=-1)
	{
		input.push_back(N);
		cin>>N;
	}

	int swaps;
	cout<<"Swaps:\t";
	cin>>swaps;

	Maximize(input,swaps);

	cout<<"Max Number:\n";
	for(int i=0;i<MaxNumber.size();i++)
		cout<<MaxNumber[i];
	cout<<endl;

	return 0;
}