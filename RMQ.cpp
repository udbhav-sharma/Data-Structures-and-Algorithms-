#include <vector>
#include <cstring>
#include <iostream>

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

Node* Tree;

void insert(Node* &T,int key)
{
	if(T==NULL)
	{
		T=new Node();
		T->key=key;
	}
	else if(T->key<key)
		insert(T->right,key);
	else
		insert(T->left,key);
}

int getHeight(Node* T)
{
	if(T==NULL)
		return -1;
	return max(getHeight(T->left),getHeight(T->right))+1;
}

void showTree(Node* T,int height,int level)
{
	if(T==NULL)
		return;
	showTree(T->left,height-1,level);
	if(height==level)
		cout<<" "<<T->key<<" ";
	else
		cout<<"   ";
	showTree(T->right,height-1,level);
}

typedef pair<int,int> pi;
std::vector<int> E;
std::vector<int> L;
std::vector<pi> H;

void generateEL(Node* T,int num)
{
	E.push_back(T->key);
	L.push_back(num);
	H.push_back(std::pair<int,int>(T->key,E.size()-1));
	if(T->left!=NULL)
	{
		generateEL(T->left,num+1);
		E.push_back(T->key);
		L.push_back(num);
	}
	if(T->right!=NULL)
	{
		generateEL(T->right,num+1);
		E.push_back(T->key);
		L.push_back(num);
	}
}

int getHval(int i)
{
	for(int j=0;j<H.size();j++)
		if(H[j].first==i)
			return H[j].second;
}

void showH(std::vector<pi> H)
{
	for(int i=0;i<H.size();i++)
		cout<<H[i].first<<", "<<H[i].second<<endl;
}

void showEL(std::vector<int> E)
{
	for(int i=0;i<E.size();i++)
		cout<<E[i]<<" ";
	cout<<endl;
}

int SegmentTree[100005];

void initializeSegmentTree()
{
	memset(SegmentTree,-1,sizeof(SegmentTree));
}

int FormSegmentTree(int i,int j,int k)
{
	if(i<j)
	{
		int x=FormSegmentTree(i,(i+j)/2,2*k+1);
		int y=FormSegmentTree((i+j)/2+1,j,2*k+2);
		if(L[x]<L[y])
			SegmentTree[k]=x;
		else
			SegmentTree[k]=y;
	}
	else if(i==j)
		SegmentTree[k]=i;
	else
	{
		cout<<"Going in i>j"<<endl;
		return -1;
	}
	return SegmentTree[k];
}

int query(int a,int b,int i,int j,int k)
{
	if(i>b || a>j)
		return -1;
	if(a>=i && b<=j)
		return SegmentTree[k];
	
	int x=query(a,(a+b)/2,i,j,2*k+1);
	int y=query((a+b)/2+1,b,i,j,2*k+2);

	if(x<0)
		return y;
	else if(y<0)
		return x;
	else if(L[x]<L[y])
		return x;
	else
		return y;
}

int main()
{
	int n;
	cin>>n;
	while(n!=-1)
	{
		insert(Tree,n);
		cin>>n;
	}

	int height=getHeight(Tree);

	cout<<"Tree:\n";
	for(int i=height;i>=0;i--)
	{
		showTree(Tree,height,i);
		cout<<endl;
	}

	generateEL(Tree,0);
	cout<<"E:\n";
	showEL(E);
	cout<<"L:\n";
	showEL(L);
	cout<<"H:\n";
	showH(H);

	initializeSegmentTree();
	FormSegmentTree(0,L.size()-1,0);

	int i,j;
	while(true)
	{
		cin>>i>>j;
		if(i==-1)
			break;
		cout<<"LCS:\t"<<E[query(0,L.size()-1,getHval(i),getHval(j),0)]<<endl;
	}
	return 0;
}