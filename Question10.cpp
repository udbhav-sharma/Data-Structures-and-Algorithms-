//Form Tree from Preorder and Inorder
#include <iostream>
#include <vector>

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

void print(Node* T)
{
	if(T==NULL)
		return;
	print(T->left);
	cout<<T->key<<" ";
	print(T->right);
}

Node* FormTree(vector<int> preorder,vector<int> inorder)
{
	if(!preorder.size() && !inorder.size())
		return NULL;
	else if(!preorder.size() || !inorder.size())
	{
		cout<<"Error\n";
		return NULL;
	}

	Node* T=new Node();
	T->key=preorder[0];

	int i,j;
	for(i=0;i<inorder.size();i++)
		if(inorder[i]==T->key)
			break;
	
	std::vector<int> new_left_inorder;
	std::vector<int> new_right_inorder;
	std::vector<int> new_left_preorder;
	std::vector<int> new_right_preorder;

	for(j=0;j<i;j++)
		new_left_inorder.push_back(inorder[j]);
	for(j=i+1;j<inorder.size();j++)
		new_right_inorder.push_back(inorder[j]);

	j=1;
	if(new_left_inorder.size())
	for(;j<preorder.size();j++)
	{
		new_left_preorder.push_back(preorder[j]);
		if(preorder[j]==new_left_inorder[new_left_inorder.size()-1])
		{
			j++;
			break;
		}
	}
	if(new_right_inorder.size())
	for(;j<preorder.size();j++)
		new_right_preorder.push_back(preorder[j]);

	T->left=FormTree(new_left_preorder,new_left_inorder);
	T->right=FormTree(new_right_preorder,new_right_inorder);
	return T;
}

int main()
{
	std::vector<int> preorder;
	std::vector<int> inorder;
	int N;

	cout<<"Preorder:\n";
	cin>>N;
	while(N!=-1)
	{
		preorder.push_back(N);
		cin>>N;
	}

	cout<<"Inorder:\n";
	cin>>N;
	while(N!=-1)
	{
		inorder.push_back(N);
		cin>>N;
	}

	print(FormTree(preorder,inorder));
	cout<<endl;
}