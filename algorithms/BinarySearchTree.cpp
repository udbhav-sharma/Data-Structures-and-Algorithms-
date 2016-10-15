#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

class Node
{
    public:
        int key;
        Node *left,*right;
    Node()
    {
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
        printf("%d ",T->key);
        Inorder(T->right);
    }
}

void Preorder(Node* T)
{
    if(T!=NULL)
    {
        printf("%d ",T->key);
        Preorder(T->left);
        Preorder(T->right);
    }
}

void Postorder(Node* T)
{
    if(T!=NULL)
    {
        Postorder(T->left);
        Postorder(T->right);
        printf("%d ",T->key);
    }
}

void Inorder_using_iteration(Node* T)
{
    stack<Node*> temp;
    bool flag=true;
    Node* k=new Node();
    temp.push(k);
    do
    {
        if(T==NULL)
        {}
        else if(flag && T->left!=NULL)
        {
            temp.push(T);
            T=T->left;
            continue;
        }
        else
        {
            flag=true;
            printf("%d ",T->key);
            T=T->right;
            continue;
        }
        T=temp.top();
        temp.pop();
        flag=false;
    }
    while(T!=k);
}

void Search(Node* T,int key)
{
    if(T==NULL)
        printf("Key is not there");
    else if(T->key==key)
        printf("Key is there");
    else if(T->key< key)
        Search(T->right,key);
    else
        Search(T->left,key);
}

void Search_using_iteration(Node *T,int key)
{
    while(T!=NULL)
    {
        if(T->key==key)
        {
            printf("Key is there");
            break;
        }
        else if(T->key< key)
            T=T->right;
        else
            T=T->left;
    }
}

int main()
{
    Node *tree=NULL;
    int t;
    scanf("%d",&t);
    while(t!=-1)
    {
        Create(tree,t);
        scanf("%d",&t);
    }
    printf("Inorder:\t");
    Inorder(tree);
    printf("\nPreorder:\t");
    Preorder(tree);
    printf("\nPostorder:\t");
    Postorder(tree);
    printf("\nInorder_using_iteration:\t");
    Inorder_using_iteration(tree);
    printf("\nEnter the value to be searched:\n");
    scanf("%d",&t);
    Search(tree,t);
    Search_using_iteration(tree,t);
    return 0;
}
