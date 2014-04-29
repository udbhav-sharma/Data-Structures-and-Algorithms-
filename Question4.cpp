/*Implement a function OneEditApart with the following signature:
bool OneEditApart(string s1,string s2)

OneEditApart("cat","Dog")=false
OneEditApart("cat","cats")=true
OneEditApart("cat","cut")=true
OneEditApart("cat","at")=true
OneEditApart("cat","acts")=false

Edit is : insertion, removal, replacement
*/

#include <iostream>

using namespace std;

bool OneEditApart(string first,string second)
{
	//Replacement
	if(first.length()==second.length())
	{
		int operations=0;
		for(int i=0;i<first.length();i++)
		{
			if(first[i]!=second[i])
				operations++;
			if(operations>1)
				return false;
		}
		return true;
	}
	//Insertion
	else if(first.length()-second.length()==1)
	{
		int operations=0;
		for(int i=0;i<second.length();)
		{
			if(first[i+operations]==second[i])
				i++;
			else
				operations++;
			if(operations>1)
				return false;
		}
		return true;
	}
	//Removal
	else if(second.length()-first.length()==1)
	{
		int operations=0;
		for(int i=0;i<first.length();)
		{
			if(second[i+operations]==first[i])
				i++;
			else
				operations++;
			if(operations>1)
				return false;
		}
		return true;
	}

	return false;
}

int main()
{
	string first,second;
	cout<<"First:\t";
	cin>>first;

	while(true)
	{
		cout<<"Second:\t";
		cin>>second;
		cout<<OneEditApart(first,second)<<endl;
	}
	return 0;
}