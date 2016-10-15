/*
http://www.geeksforgeeks.org/in-place-conversion-of-sorted-dll-to-balanced-bst/
*/
#include <iostream>

using namespace std;

#define nullptr NULL

class Node
{
public:
    int key;
    Node* left;
    Node* right;
    Node()
    {
        left=nullptr;
        right=nullptr;
    }
    Node(int key,Node* left=nullptr,Node* right=nullptr)
    {
        this->key=key;
        this->left=left;
        this->right=right;
    }
};

void insertDLL(Node*& T,int key)
{
    if(T==NULL)
        T=new Node(key);
    else
    {
        Node* p=T;
        while(p->right!=NULL)
            p=p->right;
        p->right=new Node(key,p);
    }
}

int showDLL(Node* T)
{
    int count=0;
    cout<<"DLL Forwards:\n";
    Node* prev=T;
    while(T!=nullptr)
    {
        cout<<T->key<<",";
        prev=T;
        T=T->right;
        count++;
    }

    cout<<"\nDLL Backwards:\n";
    while(prev!=nullptr)
    {
        cout<<prev->key<<",";
        prev=prev->left;
    }
    cout<<endl;
    return count;
}

Node* createBST(Node*& head,int n)
{
    if(n<=0)
        return nullptr;
    Node* prev=createBST(head,n/2);
    Node* p=head;
    head=head->right;
    Node* next=createBST(head,n-n/2-1);
    p->left=prev;
    p->right=next;
    return p;
}

void printInorder(Node* T)
{
    if(T==nullptr)
        return;
    printInorder(T->left);
    cout<<T->key<<",";
    printInorder(T->right);
}

int main()
{
    Node* head=nullptr;
    int key;
    cin>>key;
    while(key!=-1)
    {
        insertDLL(head,key);
        cin>>key;
    }

    int count=showDLL(head);
    Node* Tree=createBST(head,count);
    printInorder(Tree);
}
/*
1 2 3 4 5 6 7 8 9 -1
*/
