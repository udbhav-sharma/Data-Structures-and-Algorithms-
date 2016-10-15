#include<iostream>

using namespace std;

class Node
{
    public:
    int key;
    Node* left;
    Node* right;
    Node* parent;
    Node()
    {
        left=NULL;
        right=NULL;
        parent=NULL;
    }
};

Node* BST=NULL;

void INSERT(Node* &T,int key,Node* Parent)
{
    if(T==NULL)
    {
       T=new Node();
       T->key=key;
       T->parent=Parent;
    }
    else if(T->key>key)
        INSERT(T->left,key,T);
    else if(T->key<key)
        INSERT(T->right,key,T);
}

void INORDER(Node* T)
{
    if(T!=NULL)
    {
        INORDER(T->left);
        cout<<T->key<<" ";
        INORDER(T->right);
    }
}

int TREE_MINIMUM(Node* T)
{
    while(T->left!=NULL)
        T=T->left;
    return T->key;
}

int TREE_MAXIMUM(Node* T)
{
    while(T->right!=NULL)
        T=T->right;
    return T->key;
}

int SUCCESSOR(Node* T,int key)
{
    if(T!=NULL)
    {
        if(T->key==key)
        {
            if(T->right!=NULL)
                return TREE_MINIMUM(T->right);

            Node* r=T->parent;
            while(r!=NULL && r->left!=T)
            {
                r=r->parent;
                T=T->parent;
            }
            if(r!=NULL)
                return r->key;
            else
                return -1;
        }
        else if(T->key>key)
            SUCCESSOR(T->left,key);
        else
            SUCCESSOR(T->right,key);
    }
}

int PREDECESSOR(Node* T,int key)
{
    if(T!=NULL)
    {
        if(T->key==key)
        {
            if(T->left!=NULL)
                return TREE_MAXIMUM(T->left);

            Node* r=T->parent;
            while(r!=NULL && r->right!=T)
            {
                r=r->parent;
                T=T->parent;
            }
            if(r!=NULL)
                return r->key;
            else
                return -1;
        }
        else if(T->key>key)
            PREDECESSOR(T->left,key);
        else
            PREDECESSOR(T->right,key);
    }
}

int main()
{
    int k;

    cin>>k;
    while(k!=-1)
    {
        INSERT(BST,k,NULL);
        cin>>k;
    }

    INORDER(BST);

    cout<<"\nFor Successor:\n";
    cin>>k;
    while(k!=-1)
    {
        cout<<SUCCESSOR(BST,k)<<endl;
        cin>>k;
    }

    cout<<"For Predecessor:\n";
    cin>>k;
    while(k!=-1)
    {
        cout<<PREDECESSOR(BST,k)<<endl;
        cin>>k;
    }

    return 0;
}
