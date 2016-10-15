//Check Whether a Linked List is palindrome or not
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

void Print(Node* Link)
{
	while(Link!=NULL)
	{
		cout<<Link->key<<" ";
		Link=Link->next;
	}
	cout<<endl;
}

void Insert(Node* &Link,int key)
{
	if(Link==NULL)
	{
		Link=new Node();
		Link->key=key;
		return;
	}

	Node* p=Link;
	while(p->next!=NULL)
		p=p->next;
	p->next=new Node();
	p->next->key=key;
}

Node* Reverse(Node* Link)
{
	Node* previous=NULL;
	Node* next=NULL;
	while(Link!=NULL)
	{
		next=Link->next;
		Link->next=previous;
		previous=Link;
		Link=next;
	}
	return previous;
}

Node* Join(Node* L1,Node* L2)
{
	if(L1==NULL)
		return L2;
	while(L1->next!=NULL)
		L1=L1->next;
	L1->next=L2;
	return L1;
}

bool Compare(Node* L1,Node* L2)
{
	while(L1!=NULL && L2!=NULL)
	{
		if(L1->key!=L2->key)
			return false;
		L1=L1->next;
		L2=L2->next;
	}
	if(L1!=NULL || L2!=NULL)
		return false;
	return true;
}

bool CheckPalindrome(Node* List)
{
	if(List==NULL || List->next==NULL)
		return true;

	int count=0;
	Node* p=List;
	while(p!=NULL)
	{
		p=p->next;
		count++;
	}
	Node* middle=NULL;
	Node* reversed_List=List;

	for(int i=0;i<count/2-1;i++)
		reversed_List=reversed_List->next;
	if(count&1)
	{
		middle=reversed_List->next;
		reversed_List->next=NULL;
		reversed_List=middle->next;
		middle->next=NULL;
		reversed_List=Reverse(reversed_List);
	}
	else
	{
		middle=reversed_List;
		reversed_List=reversed_List->next;
		middle->next=NULL;
		middle=NULL;
		reversed_List=Reverse(reversed_List);
	}

	Print(List);
	Print(reversed_List);
	
	bool flag=Compare(List,reversed_List);
	Join(List,middle);
	Join(List,reversed_List);

	return flag;
}

int main()
{
	Node* List=NULL;
	int N;
	cin>>N;
	while(N!=-1)
	{
		Insert(List,N);
		cin>>N;
	}

	Print(List);
	CheckPalindrome(List)?cout<<"Palindrome\n":cout<<"Not Palindrome\n";

	return 0;
}