#include<iostream>
#include<iomanip>

using namespace std;

class Node
{
    public:

    int x,y;
    Node *left,*right;
    Node()
    {
        left=NULL;
        right=NULL;
    }
};

Node *tree=NULL;

void insert(Node* &T,int x,int y,bool flag)
{
    if(T==NULL)
    {
        T=new Node();
        T->x=x;
        T->y=y;
    }
    else if(flag)
    {
        if(x<T->x)
            insert(T->left,x,y,!flag);
        else
            insert(T->right,x,y,!flag);
    }
    else
    {
        if(y<T->y)
            insert(T->left,x,y,!flag);
        else
            insert(T->right,x,y,!flag);
    }
}

int calc_height(Node* T)
{
    if(T==NULL)
        return 0;
    else
        return(max(calc_height(T->left),calc_height(T->right))+1);
}

void print(Node* T,int height,int level)
{
    if(T!=NULL)
    {
        print(T->left,height-1,level);
        if(height==level)
        {
            cout<<setw(7)<<"("<<T->x<<","<<T->y<<")";
        }
        else
            cout<<setw(7)<<" ";
        print(T->right,height-1,level);
    }
}

bool search(Node* T,int x,int y,bool flag)
{
    if(T==NULL)
        return false;
    else if(T->x==x && T->y==y)
        return true;
    else if(flag)
    {
        if(x<T->x)
            return search(T->left,x,y,!flag);
        else
            return search(T->right,x,y,!flag);
    }
    else
    {
        if(y<T->y)
            return search(T->left,x,y,!flag);
        else
            return search(T->right,x,y,!flag);
    }
}

int main()
{
    int x,y,i,height;

    while(true)
    {
        cin>>x;
        if(x==0)
            break;
        cin>>y;

        insert(tree,x,y,true);

        height=calc_height(tree);

        for(i=height;i>=0;i--)
        {
            print(tree,height,i);
            cout<<endl;
        }
    }

    while(true)
    {
        cin>>x;
        if(x==0)
            break;
        cin>>y;

        if(search(tree,x,y,true))
            cout<<"Found\n";
        else
            cout<<"Not there\n";
    }

    return 0;
}
