/*
	Check Whether for a given set of strings anagram is there or not
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

std::vector<string> input;

bool check_anagram()
{
	int sum;
	
	if(input.size()==1)
		return true;

	for(int i=0;i<input.size();i++)
		for(int j=i+1;j<input.size();j++)
			if(input[i].length()==input[j].length())
			{
				sum=0;
				for(int k=0;k<input[i].length();k++)
				{
					sum+=input[i][k];
					sum^=input[j][k];
				}
				if(sum==0)
					return true;
			}
	return false;
}

int main()
{
	string s;

	cin>>s;
	while(s!="-1")
	{
		input.push_back(s);
		cin>>s;
	}

	cout<<check_anagram()<<endl;
	return 0;
}