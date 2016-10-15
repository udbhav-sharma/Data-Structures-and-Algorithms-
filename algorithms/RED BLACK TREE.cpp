#include <iostream>
#include <iomanip>
#define BLACK 1
#define RED 2

using namespace std;

class Node
{
    public:
        int key,color;
        Node* left;
        Node* right;
        Node* parent;
};

Node* RBT;
Node* NIL;

void ROTATE_LEFT(Node* x)
{
    Node* y=x->right;
    x->right=y->left;
    if(y->left!=NIL)
        y->left->parent=x;
    y->parent=x->parent;
    if(x->parent==NIL)
        RBT=y;
    else if(x->parent->left==x)
        x->parent->left=y;
    else
        x->parent->right=y;
    y->left=x;
    x->parent=y;
}

void ROTATE_RIGHT(Node* y)
{
    Node* x=y->left;
    y->left=x->right;

    if(x->right!=NIL)
        x->right->parent=y;

    x->parent=y->parent;
    if(y->parent==NIL)
        RBT=x;
    else if(y->parent->left==y)
        y->parent->left=x;
    else
        y->parent->right=x;

    x->right=y;
    y->parent=x;
}

void INSERT_FIXUP(Node* T,Node* z)
{
    Node* y;
    while(z->parent->color==RED)
    {
        if(z->parent==z->parent->parent->left)
        {
            y=z->parent->parent->right;
            if(y->color==RED)
            {
                z->parent->color=BLACK;
                y->color=BLACK;
                z->parent->parent->color=RED;
                z=z->parent->parent;
            }
            else
            {
                if(z==z->parent->right)
                {
                    z=z->parent;
                    ROTATE_LEFT(z);
                }
                z->parent->color=BLACK;
                z->parent->parent->color=RED;
                ROTATE_RIGHT(z->parent->parent);
            }
        }
        else
        {
            y=z->parent->parent->left;

            if(y->color==RED)
            {
                z->parent->color=BLACK;
                y->color=BLACK;
                z->parent->parent->color=RED;
                z=z->parent->parent;
            }
            else
            {
                if(z==z->parent->left)
                {
                    z=z->parent;
                    ROTATE_RIGHT(z);
                }

                z->parent->color=BLACK;
                z->parent->parent->color=RED;

                ROTATE_LEFT(z->parent->parent);
            }
        }
    }
    RBT->color=BLACK;
}

void INSERT(int key)
{
    Node* x=RBT;
    Node* y=NIL;

    while(x!=NIL)
    {
        y=x;
        if(key<x->key)
            x=x->left;
        else
            x=x->right;
    }

    Node* z=new Node();
    z->key=key;
    z->parent=y;

    if(y==NIL)
        RBT=z;
    else if(z->key<y->key)
        y->left=z;
    else
        y->right=z;

    z->left=NIL;
    z->right=NIL;
    z->color=RED;

    INSERT_FIXUP(RBT,z);

}

void PRINT(Node* T,int height,int level)
{
    if(T!=NIL)
    {
        PRINT(T->left,height-1,level);
        if(height==level)
        {
            cout.setf(ios::right);
            cout.width(3);
            cout<<T->key;
            cout<<",";
            cout.unsetf(ios::right);
            cout.setf(ios::left);
            cout.width(6);
            if(T->color==RED)
                cout<<"RED";
            else
                cout<<"BLACK";
        }
        else
        {
            cout.width(10);
            cout<<" ";
        }
        PRINT(T->right,height-1,level);
    }
}

int Height(Node* T)
{
    if(T==NIL)
        return -1;
    else
        return (max(Height(T->left),Height(T->right))+1);
}

int main()
{
    NIL=new Node();
    NIL->color=BLACK;
    NIL->left=NULL;
    NIL->right=NULL;
    RBT=NIL;
    RBT->parent=NIL;

    int k,height;

    cin>>k;
    while(k!=-1)
    {
        INSERT(k);
        height=Height(RBT);
        for(k=height;k>=0;k--)
        {
            PRINT(RBT,height,k);
            cout<<endl;
        }
        cin>>k;
    }
    return 0;
}
/*
5 8 2 4 3 12 23 22 18 17 14 28 18 19 16 20 -1
*/
