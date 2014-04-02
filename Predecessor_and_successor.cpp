#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;

class Node
{
    public:
        int key;
        Node *left,*right,*parent;
    Node()
    {
        left=NULL;
        right=NULL;
        parent=NULL;
    }
};

void Create(Node* &T,int k,Node* parent)
{
    if(T==NULL)
    {
        T=new Node();
        T->key=k;
        T->parent=parent;
    }
    else if(T->key>k)
        Create(T->left,k,T);
    else
        Create(T->right,k,T);
}

Node* Search(Node* T,int k)
{
    if(T!=NULL)
    {
        if(T->key==k)
            return T;
        else if(T->key<k)
            return Search(T->right,k);
        else
            return Search(T->left,k);
    }
    return NULL;
}

Node* treeminimum(Node* T)
{
    while(T->left!=NULL)
        T=T->left;
    return T;
}

Node* Successor(Node* x)
{
    Node* y;
    if(x->right!=NULL)
        return(treeminimum(x->right));
    y=x->parent;
    while(y->left!=x)
    {
        x=y;
        y=y->parent;
    }
    return y;
}

void Inorder(Node* T)
{
    if(T!=NULL)
    {
        Inorder(T->left);
        printf("%d ",T->key);
        Inorder(T->right);
    }
}

int heightOfTree(Node* T)
{
    int k1,k2;
    if(T!=NULL)
    {
        k1=heightOfTree(T->left)+1;
        k2=heightOfTree(T->right)+1;
        if(k1>k2)
            return k1;
        else
            return k2;
    }
    return 0;
}

void printTree(Node* T,int Height,int level)
{
    if(T->left!=NULL)
        printTree(T->left,Height,level-1);
    if(Height==level)
        cout<<setw(3)<<T->key;
    else
        cout<<setw(3)<<"   ";
    if(T->right!=NULL)
        printTree(T->right,Height,level-1);
}

void transplant(Node* &T,Node* u,Node* v)
{
    if(u->parent==NULL)
        T=v;
    else if(u==u->parent->left)
        u->parent->left=v;
    else
        u->parent->right=v;
    if(v!=NULL)
        v->parent=u->parent;
}

void deleteNode(Node* &T,Node* x)
{
    if(x->left==NULL)
        transplant(T,x,x->right);
    else if(x->right==NULL)
        transplant(T,x,x->left);
    else
    {
        Node* y;
        y=treeminimum(x->right);
        if(y->parent!=x)
        {
            transplant(T,y,y->right);
            y->right=x->right;
            y->right->parent=y;
        }
        transplant(T,x,y);
        y->left=x->left;
        y->left->parent=y;
    }
}

int main()
{
    Node *tree=NULL,*y;
    int t,i;
    scanf("%d",&t);
    while(t!=0)
    {
        Create(tree,t,NULL);
        scanf("%d",&t);
    }
    t=heightOfTree(tree);
    for(i=t;i>=0;i--)
    {
        cout<<endl;
        printTree(tree,i,t);
    }
    cout<<"Enter the value to be deleted";
    cin>>t;
    while(t!=0)
    {
        y=Search(tree,t);
        cin>>t;
    }
    return 0;
}
/*
26
18
80
9
24
70
90
5
14
20
25
60
75
85
98
64
78
77
0
*/
