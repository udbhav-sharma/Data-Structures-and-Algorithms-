#include<iostream>
#include<cstdlib>
#include<time.h>
#include<iomanip>

using namespace std;

class Node
{
    public:
        int key;
        int priority;
        Node* left;
        Node* right;
        Node* parent;
        Node()
        {
            left=NULL;
            right=NULL;
            parent=NULL;
            priority=rand()%100+1;
        }
};

Node* Treap=NULL;

void rotate_left(Node* &k1)
{
    Node* k2=k1->right;
    k1->right=k2->left;
    k2->left=k1;
    k1=k2;
}

void rotate_right(Node* &k1)
{
    Node* k2=k1->left;
    k1->left=k2->right;
    k2->right=k1;
    k1=k2;
}

void INSERT(Node* &T,int key)
{
    if(T==NULL)
    {
        T=new Node();
        T->key=key;
    }
    else if(T->key<key)
    {
        INSERT(T->right,key);
        if(T->right->priority<T->priority)
            rotate_left(T);
    }
    else if(T->key>key)
    {
        INSERT(T->left,key);
        if(T->left->priority<T->priority)
            rotate_right(T);
    }
}

int Height(Node* T)
{
    if(T!=NULL)
        return (max(Height(T->left),Height(T->right))+1);
    else
        return -1;
}

void PRINT(Node* T,int Height,int level)
{
    if(T!=NULL)
    {
        PRINT(T->left,Height-1,level);

        if(Height==level)
        {
            cout.setf(ios::right);
            cout.width(2);
            cout<<T->key;

            cout<<",";

            cout.unsetf(ios::right);
            cout.setf(ios::left);
            cout.width(2);
            cout<<T->priority<<" ";
        }
        else
        {
            cout.setf(ios::left);
            cout.width(6);
            cout<<" ";
        }

        PRINT(T->right,Height-1,level);
    }
}

int main()
{
    srand(time(NULL));
    int n,i,height;

    cin>>n;

    while(n!=-1)
    {
        INSERT(Treap,n);
        cin>>n;
    }

    height=Height(Treap);

    for(i=height;i>=0;i--)
    {
        PRINT(Treap,height,i);
        cout<<endl;
    }
}

/*
2
4
6 9 3 5 7 8 12 45 4 41 42 19 20 26 23 36
-1
*/
