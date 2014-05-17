#include <iostream>
#include <queue>

#define infinity 100007

using namespace std;

struct compare  
 {  
   bool operator()(const int& l, const int& r)  
   {  
       return l > r;  
   }  
 };  

double Median=infinity;

int main()
{
	std::priority_queue<int> left;
	std::priority_queue<int,std::vector<int>,compare> right;
	int n;

	cout<<"Enter the elements\n";
	cin>>n;
	while(n!=-1)
	{
		if(n>Median)
			right.push(n);
		else if(n<Median)
			left.push(n);
		else
		{
			if(left.size()<=right.size())
				left.push(n);
			else 
				right.push(n);
		}
		if(((int)left.size())-((int)right.size())>1)
		{
			right.push(left.top());
			left.pop();
		}
		else if(((int)left.size())-((int)right.size())>1)
		{
			left.push(right.top());
			right.pop();
		}
		if((int)left.size()>(int)right.size())
			Median=left.top();
		else if((int)left.size()==(int)right.size())
			Median=(left.top()+right.top())/2.0;
		else
			Median=right.top();
		cout<<"Median = "<<Median<<endl;
		cin>>n;
	}
	return 0;
}