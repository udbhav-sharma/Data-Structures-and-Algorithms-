#include<iostream>
#include<iomanip>

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

Node* PDS=NULL;
Node* BST=NULL;

void INSERT(Node* &T1,Node* &T2,int key)
{
    if(T1==NULL)
    {
        T2=new Node();
        T2->key=key;
    }
    else if(T1->key<key)
    {
        T2=new Node();
        T2->key=T1->key;
        T2->left=T1->left;
        INSERT(T1->right,T2->right,key);
    }
    else if(T1->key>key)
    {
        T2=new Node();
        T2->key=T1->key;
        T2->right=T1->right;
        INSERT(T1->left,T2->left,key);
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
            cout.width(3);
            cout<<T->key;
        }
        else
        {
            cout.setf(ios::left);
            cout.width(3);
            cout<<" ";
        }

        PRINT(T->right,Height-1,level);
    }
}

int main()
{
    int k,i,height;
    cout<<"INPUT:";
    cin>>k;
    while(k!=-1)
    {
        BST=PDS;
        INSERT(BST,PDS,k);

        cout<<"\n----------------------------BST-------------------------------\n";
        height=Height(BST);
        for(i=height;i>=0;i--)
        {
            PRINT(BST,height,i);
            cout<<endl;
        }

        cout<<"\n----------------------------PDS-------------------------------\n";
        height=Height(PDS);
        for(i=height;i>=0;i--)
        {
            PRINT(PDS,height,i);
            cout<<endl;
        }
        cout<<"INPUT:";
        cin>>k;
    }
    return 0;
}
