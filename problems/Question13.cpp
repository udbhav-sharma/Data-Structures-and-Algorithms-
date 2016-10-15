//Find kth smallest element in a BST
#include <iostream>

using namespace std;

class Node
{
    public:
        int key;
        int leftSize;
        Node *left,*right;
    Node()
    {
        leftSize=0;
        left=NULL;
        right=NULL;
    }
};

void Create(Node* &T,int k)
{
    if(T==NULL)
    {
        T=new Node();
        T->key=k;
    }
    else if(T->key>k)
        Create(T->left,k);
    else
        Create(T->right,k);
}

void Inorder(Node* T)
{
    if(T!=NULL)
    {
        Inorder(T->left);
        cout<<T->key<<" "<<T->leftSize<<endl;
        Inorder(T->right);
    }
}

int GetChildren(Node* T)
{
    if(T==NULL)
        return 0;
    
    int leftChildren=GetChildren(T->left);
    int rightChildren=GetChildren(T->right);
    
    T->leftSize=leftChildren+1;
    
    return leftChildren+rightChildren+1;
}

int Search(Node* T,int k)
{
    if(T==NULL)
        return -1;
    if(T->leftSize>k)
        return Search(T->left,k);
    else if(T->leftSize==k)
        return T->key;
    else
        return Search(T->right,k-T->leftSize);
}

int main()
{
    Node *tree=NULL;
    int t;
    
    cin>>t;
    while(t!=-1)
    {
        Create(tree,t);
        cin>>t;
    }

    GetChildren(tree);

    cout<<"Inorder:\n";
    Inorder(tree);

    cout<<"Kth smallest element:\t";
    cin>>t;
    cout<<Search(tree,t)<<endl;

    return 0;
}
