#include <iostream>
using namespace std;

class Node
{
    public:
    int key;
    bool rightthread;
    Node* left;
    Node* right;
    Node()
    {
        rightthread=true;
        left=false;
        right=false;
    }
};

void Insert(Node* &T,int key,Node* successor,bool rightthread)
{
    if(T==NULL || rightthread)
    {
        T=new Node();
        T->key=key;
        T->right=successor;
    }
    else if(T->key>key)
        Insert(T->left,key,T,false);
    else if(T->key<key)
    {
        Insert(T->right,key,T->right,T->rightthread);
        T->rightthread=false;
    }
}

Node* Search(Node* T,int key)
{
    if(T==NULL)
        return NULL;
    else if(T->key==key)
        return T;
    else if(T->key>key)
        return Search(T->left,key);
    else
        return Search(T->right,key);
}

void PrintTree(Node* T)
{
    if(T==NULL)
        return;
    PrintTree(T->left);
    cout<<T->key<<", ";
    if(!T->rightthread)
        PrintTree(T->right);
}

void PrintKey(Node* T)
{
    if(T==NULL)
        cout<<"-1"<<endl;
    else
        cout<<T->key<<endl;
}

void Successor(Node* T)
{
    if(T->rightthread)
        PrintKey(T->right);
    else
    {
        T=T->right;
        if(T==NULL)
            return NULL;
        while(T->left!=NULL)
            T=T->left;
        PrintKey(T);
    }
}

int main()
{
    int n;
    Node* Tree=NULL;
    cin>>n;
    while(n!=-1)
    {
        Insert(Tree,n,NULL,false);
        cin>>n;
    }
    cout<<"--------------Tree-------------\n";
    PrintTree(Tree);
    cout<<endl;

    Node* T;
    cin>>n;
    while(n!=-1)
    {
        T=Search(Tree,n);
        if(T!=NULL)
            Successor(T);
        else
            PrintKey(T);
        cin>>n;
    }
    return 0;
}
