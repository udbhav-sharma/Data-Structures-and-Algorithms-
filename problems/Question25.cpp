#include<iostream>
#include<stdio.h>

#define nullptr NULL

using namespace std;

class Node
{
    public:
        int key;
        Node *left,*right;
    Node()
    {
        left=nullptr;
        right=nullptr;
    }
};

void Create(Node* &T,int k)
{
    if(T==nullptr)
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
    if(T!=nullptr)
    {
        Inorder(T->left);
        printf("%d ",T->key);
        Inorder(T->right);
    }
}

void buildDLLFromBST(Node* T,Node*& head)
{
    static Node* prev=NULL;
    if(T==nullptr)
        return;
    buildDLLFromBST(T->left,head);
    T->left=prev;
    prev==nullptr ? head=T:prev->right=T;
    prev=T;
    buildDLLFromBST(T->right,head);
}

void printDLLList(Node* T)
{
    while(T!=nullptr)
    {
        cout<<T->key<<",";
        T=T->right;
    }
    cout<<endl;
}

int main()
{
    Node *tree=nullptr;
    int t;
    scanf("%d",&t);
    while(t!=-1)
    {
        Create(tree,t);
        scanf("%d",&t);
    }
    printf("Inorder:\n");
    Inorder(tree);
    printf("\n");
    Node* head=nullptr;
    buildDLLFromBST(tree,head);
    printf("List:\n");
    printDLLList(head);
    return 0;
}
/*
9 4 5 7 2 10 13 34 23 27 25 19 30 22 -1
*/
