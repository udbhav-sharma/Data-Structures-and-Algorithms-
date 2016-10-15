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

Node* TREE_MINIMUM(Node* T)
{
    while(T->left!=NULL)
        T=T->left;
    return T;
}

Node* TREE_MAXIMUM(Node* T)
{
    while(T->right!=NULL)
        T=T->right;
    return T;
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

void TRANSPLANT(Node* &T,Node* u,Node* v)
{
    if(u->parent==NULL)
        T=v;
    else if(u->parent->left==u)
        u->parent->left=v;
    else
        u->parent->right=v;
    if(v!=NULL)
        v->parent=u->parent;
}

void DELETE(Node* &T,int key)
{
    Node* z=Search(T,key);
    if(z!=NULL)
    {
        if(z->left==NULL)
            TRANSPLANT(T,z,z->right);
        else if(z->right==NULL)
            TRANSPLANT(T,z,z->left);
        else
        {
            Node* r=TREE_MINIMUM(z->right);
            if(r->parent!=z)
            {
                TRANSPLANT(T,r,r->right);
                r->right=z->right;
                r->right->parent=r;
            }
            TRANSPLANT(T,z,r);
            r->left=z->left;
            r->left->parent=r;
        }
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
    cout<<endl;

    cin>>k;
    while(k!=-1)
    {
        DELETE(BST,k);
        INORDER(BST);
        cout<<endl;
        cin>>k;
    }

    return 0;
}
