#include <iostream>
using namespace std;

class Node
{
    public:
    int key;
    bool rightthread;
    Node* left;
    Node* right;
    Node* parent;
    Node()
    {
        rightthread=true;
        left=NULL;
        right=NULL;
        parent=NULL;
    }
};

void Insert(Node* &T,int key,Node* parent,Node* successor,bool rightthread)
{
    if(T==NULL || rightthread)
    {
        T=new Node();
        T->key=key;
        T->right=successor;
        T->parent=parent;
    }
    else if(T->key>key)
        Insert(T->left,key,T,T,false);
    else if(T->key<key)
    {
        Insert(T->right,key,T,T->right,T->rightthread);
        T->rightthread=false;
    }
}

Node* Search(Node* T,int key,bool rightthread)
{
    if(T==NULL || rightthread)
        return NULL;
    else if(T->key==key)
        return T;
    else if(T->key>key)
        return Search(T->left,key,false);
    else
        return Search(T->right,key,T->rightthread);
}

void PrintTree(Node* T,bool rightthread)
{
    if(T==NULL || rightthread)
        return;
    PrintTree(T->left,false);
    cout<<T->key<<", ";
    PrintTree(T->right,T->rightthread);
}

void PrintKey(Node* T)
{
    if(T==NULL)
        cout<<"-1"<<endl;
    else
        cout<<T->key<<endl;
}

Node* Tree_Minimum(Node* T)
{
    while(T->left!=NULL)
        T=T->left;
    return T;
}

Node* Successor(Node* T)
{
    if(T->rightthread)
        return(T->right);
    else
    {
        if(T->right!=NULL)
            return(Tree_Minimum(T->right));
        while(T->parent!=NULL && T->parent->right==T)
            T=T->parent;
        return(T->parent);
    }
}

int main()
{
    int n;
    Node* Tree=NULL;
    cin>>n;
    while(n!=-1)
    {
        Insert(Tree,n,NULL,NULL,false);
        cin>>n;
    }
    cout<<"--------------Tree-------------\n";
    PrintTree(Tree,false);
    cout<<endl;

    Node* T;
    cin>>n;
    while(n!=-1)
    {
        T=Search(Tree,n,false);
        if(T!=NULL)
            PrintKey(Successor(T));
        else
            PrintKey(T);
        cin>>n;
    }
    return 0;
}
