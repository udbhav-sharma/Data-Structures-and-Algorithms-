#include<iostream>
#include<iomanip>

using namespace std;

class Node
{
    public:

    int height,key;
    Node *lchild,*rchild;

    Node()
    {
        lchild=NULL;
        rchild=NULL;
    }
};

int height(Node* T)
{
    if(T==NULL)
        return -1;
    else
        return T->height;
}

void RotateWithLeftChild(Node*& k1)
{
    Node* k2=k1->lchild;
    k1->lchild=k2->rchild;
    k2->rchild=k1;
    k1->height=max(height(k1->lchild),height(k1->rchild))+1;
    k2->height=max(height(k2->lchild),height(k2->rchild))+1;
    k1=k2;
}

void RotateWithRightChild(Node*& k1)
{
    Node* k2=k1->rchild;
    k1->rchild=k2->lchild;
    k2->lchild=k1;
    k1->height=max(height(k1->lchild),height(k1->rchild))+1;
    k2->height=max(height(k2->lchild),height(k2->rchild))+1;
    k1=k2;
}

void doubleRotateWithLeftChild(Node*& k1)
{
    RotateWithRightChild(k1->lchild);
    RotateWithLeftChild(k1);
}

void doubleRotateWithRightChild(Node*& k1)
{
    RotateWithLeftChild(k1->rchild);
    RotateWithRightChild(k1);
}

void insert(Node* &T,int key)
{
    if(T==NULL)
    {
        T=new Node();
        T->key=key;
    }
    else if(key<T->key)
    {
        insert(T->lchild,key);
        if(height(T->lchild)-height(T->rchild)==2)
        {
            if(T->lchild->key<key)
                doubleRotateWithLeftChild(T);
            else
                RotateWithLeftChild(T);
        }
    }
    else if(key>T->key)
    {
        insert(T->rchild,key);
        if(height(T->rchild)-height(T->lchild)==2)
        {
            if(T->rchild->key>key)
                doubleRotateWithRightChild(T);
            else
                RotateWithRightChild(T);
        }
    }
    T->height=max(height(T->lchild),height(T->rchild))+1;
}

void print(Node* T,int h,int level)
{
    if(T!=NULL)
    {
        print(T->lchild,h-1,level);

        if(h==level)
            cout<<setw(7)<<T->key<<" "<<T->height;
        else
            cout<<setw(7)<<" ";

        print(T->rchild,h-1,level);
    }
}

int main()
{
    int key,i;
    Node* tree=NULL;

    cin>>key;
    while(key!=-1)
    {
        insert(tree,key);
        for(i=tree->height;i>=0;i--)
        {
            print(tree,tree->height,i);
            cout<<endl;
        }
        cin>>key;
    }

    return 0;
}
