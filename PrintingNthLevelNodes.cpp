#include <iostream>
#include <queue>

using namespace std;

class Node
{
	public:
		int key;
		Node* left;
		Node* right;
		Node()
		{
			left=NULL;
			right=NULL;
		} 
};

Node* Empty_Node;

void insert(Node* &T,int key)
{
	if(T==NULL)
	{
		T=new Node();
		T->key=key;
	}
	else if(T->key>=key)
		insert(T->left,key);
	else
		insert(T->right,key);
}

void PrintNthlevel(Node* T,int N)
{
	int level=0;
	if(T==NULL)
		return;
	queue<Node*> q;
	q.push(T);
	q.push(Empty_Node);
	while(level<=N)
	{
		T=q.front();
		q.pop();
		if(q.empty())
			break;
		else if(T==Empty_Node)
		{
			q.push(Empty_Node);
			//cout<<endl;
			level++;
		}
		else if(T!=NULL)
		{
			if(level==N)
				cout<<T->key<<" ";
			q.push(T->left);
			q.push(T->right);
		}
	}
}

int main()
{
	Empty_Node=new Node();
	Empty_Node->key=-1;

	Node* tree=NULL;
	int N;
	
	cout<<"Input:\n";
	cin>>N;
	while(N!=-1)
	{
		insert(tree,N);
		cin>>N;
	}
	cout<<"Level starts from Zero:\t";
	cin>>N;
	PrintNthlevel(tree,N);
	cout<<endl;
	return 0;
}