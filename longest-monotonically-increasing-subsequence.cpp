#include <vector>
#include <iostream>
#define infinity 100007

using namespace std;

typedef std::vector<int> vi;

std::vector<vi> List;

int cmin=infinity;
int cmax=-infinity;

int getMaxList(long long n)
{
	int temp_max=-infinity,index=-1;
	for(int i=0;i<List.size();i++)
	{
		if(List[i][List[i].size()-1] <=n && List[i][List[i].size()-1]>=temp_max)
		{
			index=i;
			temp_max=List[i][List[i].size()-1];
		}
	}
	return index;
}

void removeList(int size)
{
	for(int i=0;i<List.size()-1;i++)
		if(List[i].size()==size)
		{
			List.erase(List.begin()+i);
			removeList(size);
			return;
		}
}

void showList(int i)
{
	for(int j=0;j<List[i].size();j++)
		cout<<List[i][j]<<" ";
	cout<<endl;
}

void printList()
{
	int index=-1,temp_max=-infinity;

	for(int i=0;i<List.size();i++)
	{
		int j=List[i].size();
		if(j>temp_max)
		{
			temp_max=List[i].size();
			index=i;
		}
	}

	cout<<"Sequence is:\n";
	showList(index);
}

void enterNumber(int n)
{	
	if(n<cmin)
	{
		cmin=n;
		vi temp;
		temp.push_back(n);
		List.push_back(temp);
	}
	else if(n>cmax)
	{
		cmax=n;
		vi temp=List[getMaxList(infinity)];
		temp.push_back(n);
		List.push_back(temp);
	}
	else
	{
		vi temp=List[getMaxList(n)];
		temp.push_back(n);
		List.push_back(temp);
		removeList(temp.size());
	}

	for(int i=0;i<List.size();i++)
	{
		cout<<i<<"\t";
		showList(i);
	}
}

int main()
{
	int n;
	cout<<"Enter Input for ending -1\n";

	cin>>n;
	while(n!=-1)
	{
		enterNumber(n);
		cin>>n;
	}

	printList();

	return 0;
}