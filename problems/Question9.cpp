/* Build a binary tree using it's inorder & levelorder tree traversal. */

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

std::vector<int> getLevelorder(std::vector<int> Inorder, std::vector<int> Levelorder)
{
	std::vector<int> newLevelorder;
	for(int i=0;i<Levelorder.size() && newLevelorder.size()<Inorder.size();i++)
		for(int j=0;j<Inorder.size();j++)
			if(Inorder[j]==Levelorder[i])
				newLevelorder.push_back(Levelorder[i]);

	return newLevelorder;
}

Node* FormTree(std::vector<int> Inorder,std::vector<int> Levelorder)
{
	if(Levelorder.size()==0 || Inorder.size()==0)
		return NULL;

	Node* T=new Node();
	T->key=Levelorder[0];

	int i;
	for(i=0;i<Inorder.size();i++)
		if(Inorder[i]==T->key)
			break;

	std::vector<int> newInorder;

	//For left subtree
	if(i>0)
	{
		newInorder.insert(newInorder.begin(),Inorder.begin(),Inorder.begin()+i);
		T->left=FormTree(newInorder,getLevelorder(newInorder,Levelorder));
	}

	//For right subtree
	if(i!=Inorder.size()-1)
	{
		newInorder.erase(newInorder.begin(),newInorder.end());
		newInorder.insert(newInorder.begin(),Inorder.begin()+i+1,Inorder.end());
		T->right=FormTree(newInorder,getLevelorder(newInorder,Levelorder));
	}
	return T;
} 

int Height(Node* T)
{
	if(T==NULL)
		return -1;
	return (max(Height(T->left),Height(T->right))+1);
}

void printTree(Node* T,int height,int level)
{
	if(T==NULL)
		return;

	printTree(T->left,height-1,level);
	if(height==level)
		cout<<T->key;
	else
		cout<<" ";
	printTree(T->right,height-1,level);
}

std::vector<int> input(string Type)
{
	std::vector<int> v;
	int n;
	cout<<Type<<":"<<endl;
	cin>>n;
	while(n!=-1)
	{
		v.push_back(n);
		cin>>n;
	}
	return v;
}

int main()
{
	std::vector<int> Inorder;
	std::vector<int> Levelorder;

	Inorder=input("Inorder");
	Levelorder=input("Levelorder");

	Node* tree=FormTree(Inorder,Levelorder);
	
	int height=Height(tree);

	for(int i=height;i>=0;i--)
	{
		printTree(tree,height,i);
		cout<<endl;
	}
	return 0;
}