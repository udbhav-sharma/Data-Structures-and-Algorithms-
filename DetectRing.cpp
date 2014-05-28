#include <iostream>

using namespace std;

class Node{
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

void FormCycle(Node* L,Node* T)
{
	while(L->next!=NULL)
		L=L->next;
	L->next=T;
}

Node* getPointer(Node* L,int key)
{
	while(L!=NULL && L->key!=key)
		L=L->next;
	return L;
}

bool detectRing(Node* L)
{
	if(L==NULL)
		return false;
	Node* First=L;
	Node* Second=L;
	do
	{
		First=First->next;
		Second=Second->next;
		if(Second==NULL)
			break;
		Second=Second->next;
	}
	while(First!=NULL && Second!=NULL && First!=Second);
	if(First==NULL || Second==NULL)
		return false;
	cout<<Second->key<<endl;
	return true;
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

int main()
{
	int N;
	Node* List;
	cout<<"Input:\n";
	cin>>N;
	while(N!=-1)
	{
		insert(List,N);
		cin>>N;
	}
	cout<<"Cycle from tail to:\t";
	cin>>N;
	print(List);
	FormCycle(List,getPointer(List,N));
	detectRing(List)? cout<<"Ring\n":cout<<"No Ring\n";
	return 0;
}