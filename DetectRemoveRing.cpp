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

Node* detectRing(Node* L)
{
	if(L==NULL)
		return NULL;
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
		return NULL;
	return Second;
}

void removeRing(Node* List,Node* K)
{
	Node* p1=K;
	Node* p2=K;
	int count=1;
	while(p1->next!=p2)
	{
		count++;
		p1=p1->next;
	}

	p1=List;
	p2=List;
	for(int i=0;i<count;i++)
		p2=p2->next;

	while(p1!=p2)
	{
		p1=p1->next;
		p2=p2->next;
	}

	while(p2->next!=p1)
		p2=p2->next;
	p2->next=NULL;
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
	Node* List=NULL;
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
	Node* K;
	(K=detectRing(List))!=NULL? cout<<"Ring\n":cout<<"No Ring\n";
	
	if(K!=NULL)
	{
		removeRing(List,K);
		print(List);
	}
	return 0;
}