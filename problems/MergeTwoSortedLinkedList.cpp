#include <iostream>

using namespace std;

class Node
{
	public:
	int key;
	Node* next;
	Node()
	{
		next=NULL;
	}
};

void insert(Node* &L,int key)
{
	if(L==NULL)
	{
		L=new Node();
		L->key=key;
		return;
	}
	Node* T=L;
	while(T->next!=NULL)
		T=T->next;
	T->next=new Node();
	T->next->key=key;
}

void print(Node* L)
{
	int k;
	cout<<"List:\n";
	while(L!=NULL)
	{
		cout<<L->key<<" ";
		L=L->next;
	}
	cout<<endl;
}

Node* Merge(Node* List1,Node* List2)
{
	Node* List=new Node();
	Node* L=List;
	while(List1!=NULL && List2!=NULL)
	{
		if(List1->key<List2->key)
		{
		    L->next=List1;
			List1=List1->next;
		}
		else if(List1->key==List2->key)
		{
			L->next=List2;
			List1=List1->next;
			List2=List2->next;
		}
		else
		{
			L->next=List2;
			List2=List2->next;
		}
		L=L->next;
	}
	while(List1!=NULL)
	{
		L->next=List1;
		List1=List1->next;
		L=L->next;
	}
	while(List2!=NULL)
	{
		L->next=List2;
		List2=List2->next;
		L=L->next;
	}
	return List->next;
}

int main()
{
	int N;
	Node* List1=NULL;
	Node* List2=NULL;

	cout<<"Input for List1:\n";
	cin>>N;
	while(N!=-1)
	{
		insert(List1,N);
		cin>>N;
	}

	cout<<"Input for List2:\n";
	cin>>N;
	while(N!=-1)
	{
		insert(List2,N);
		cin>>N;
	}

	print(Merge(List1,List2));
	return 0;
}