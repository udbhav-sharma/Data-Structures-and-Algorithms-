#include <iostream>
#include <iomanip>

using namespace std;

int degree;
int height=0;

class Node
{
    public:
    int size;//To determine number of Keys in a particular node
    int *key;//To store values of key
    bool leaf;//To check whether it's leaf or not
    Node **child;//Pointer towards children
    Node()//Initializing class variables
    {
        size=0;
        leaf=true;
        key=new int[2*degree-1];
        child=new Node*[2*degree];
        for(int i=0;i<2*degree;i++)
            child[i]=NULL;
    }
    bool IsFull()
    {
        return (size==(2*degree-1));
    }
};

Node *Btree=NULL;

void SPLIT_CHILD(Node* T,int i)
{
    int j;
    Node* s=new Node();
    Node* r=T->child[i];
    s->leaf=r->leaf;//Assigning new node whether it's leaf or not

    //adjusting child's key
    for(j=0;j<degree-1;j++)
        s->key[j]=r->key[degree+j];

    //adjusting child's pointer
    if(!r->leaf)
    {
        for(j=0;j<degree;j++)
            s->child[j]=r->child[degree+j];
    }

    //adjusting child's size
    r->size=degree-1;
    s->size=degree-1;

    //adjusting parent's key
    for(j=T->size-1;j>=i;j--)
        T->key[j+1]=T->key[j];

    //adjusting parent's pointer
    for(j=T->size;j>i;j--)
        T->child[j+1]=T->child[j];

    T->child[i+1]=s;
    T->key[i]=r->key[degree-1];
    T->size++;
}

void INSERT_INTO_CHILD(Node* T,int n)
{
    int i=T->size-1;
    if(T->leaf)
    {
        while(i>=0 && n<T->key[i])
        {
            T->key[i+1]=T->key[i];
            i--;
        }
        T->key[i+1]=n;
        T->size++;
    }
    else
    {
        while(i>=0 && n<T->key[i])
            i--;
        i++;
        if(T->child[i]->IsFull())
        {
            SPLIT_CHILD(T,i);
            if(n>T->key[i])
                i++;
        }
        INSERT_INTO_CHILD(T->child[i],n);
    }
}

void INSERT(int n)
{
    if(Btree->IsFull())
    {
        Node* r=Btree;
        Btree=new Node();
        Btree->leaf=false;
        Btree->child[0]=r;
        SPLIT_CHILD(Btree,0);
        height++;
    }
    INSERT_INTO_CHILD(Btree,n);
}

void CREATE(int n)
{
    degree=n;
    Btree=new Node();
}

void PRINT(Node* T,int height,int level)
{
    int i;
    if(T!=NULL)
    {
        for(i=0;i<T->size;i++)
        {
            PRINT(T->child[i],height-1,level);
            if(height==level)
                cout<<setw(4)<<T->key[i];
            else
                cout<<setw(4)<<" ";
        }
        PRINT(T->child[i],height-1,level);
    }
}

int main()
{
    int n;
    cout<<"Enter the degree\n";
    while(true)
    {
        cin>>n;
        if(n<=1)
            cout<<"Enter the degree again\n";
        else
            break;
    }

    CREATE(n);

    cout<<"Enter the values. For ending please enter -1\n";
    cin>>n;
    while(n!=-1)
    {
        INSERT(n);
        cin>>n;
    }

    for(n=height;n>=0;n--)
    {
        PRINT(Btree,height,n);
        cout<<endl;
    }

    return 0;
}
/*
5
6
1
2
8
9
12
14
26
23
20
21
48
79
60
52
47
44
33
100
67
53
45
101
93
24
111
7
17
39
0
*/
