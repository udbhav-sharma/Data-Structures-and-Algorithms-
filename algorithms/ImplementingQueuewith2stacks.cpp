#include <iostream>
#include <stack>

using namespace std;

class queue
{
	private:
		stack<int> s1;
		stack<int> s2;
	public:
		void enqueue(int key);
		int dequeue();
};

void queue::enqueue(int key)
{
	s1.push(key);
}

int queue::dequeue()
{
	if(!s2.size())
	{
		while(s1.size())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}
	if(s2.size())
	{
		int k=s2.top();
		s2.pop();
		return k;
	}
	else
	{
		cout<<"Queue is empty\n";
		return -1;
	}
}

int main()
{
	queue q;
	int Flag,N,k;
	while(true)
	{
		cin>>N;
		if(N<=0)
			cout<<"Dequeue:\t"<<q.dequeue()<<endl;
		else
			q.enqueue(N);
	}
	return 0;
}