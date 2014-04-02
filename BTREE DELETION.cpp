#include<iostream>
#include<iomanip>

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
        if(T->child[i]->size==2*degree-1)
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
    if(Btree->size==2*degree-1)
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

int Height(Node* T)
{
    if(T->leaf)
        return 0;
    else
        return(Height(T->child[0])+1);
}

void DELETE_FROM_LEAF(Node* T,int i)
{
    int k;
    for(k=i;k<T->size-1;k++)
        T->key[k]=T->key[k+1];
    (T->size)--;
}

int Replace_Predecessor(Node* T)
{
    while(!T->leaf)
        T=T->child[T->size];
    int k=T->key[T->size-1];
    DELETE_FROM_LEAF(T,T->size-1);
    return k;
}

int Replace_Successor(Node* T)
{
    while(!T->leaf)
        T=T->child[0];
    int k=T->key[0];
    DELETE_FROM_LEAF(T,0);
    return k;
}

void Merge(Node* T,int i)
{
    int k;
    Node* r=T->child[i];
    Node* s=T->child[i+1];

    //Lowering Down Parent's key
    r->key[r->size++]=T->key[i];

    //Merging Both Nodes Keys and Pointers
    for(k=0;k<s->size;k++)
    {
        r->key[r->size]=s->key[k];
        r->child[r->size++]=s->child[k];
    }
    r->child[r->size]=s->child[k];

    //Adjusting Parent's Keys and Pointers
    for(k=i;k<T->size-1;k++)
    {
        T->key[i]=T->key[i+1];
        T->child[i+1]=T->child[i+2];
    }
    T->size--;
}

void DELETE(Node* T,int n)
{
    if(T!=NULL)
    {
        int i;

        for(i=0;i<T->size;i++)
        {
            if(T->key[i]==n)
            {
                if(T->leaf)
                {
                    DELETE_FROM_LEAF(T,i);
                }
                else
                {
                    if(T->child[i]->size>=degree)
                    {
                        T->key[i]=Replace_Predecessor(T->child[i]);
                    }
                    else if(T->child[i+1]->size>=degree)
                    {
                        T->key[i]=Replace_Successor(T->child[i+1]);
                    }
                    else
                    {
                        //Merge Both Nodes
                        Merge(T,i);
                        DELETE(T->child[i],n);
                    }
                }
                return;
            }
            else if(T->key[i]>n)
                break;
        }

        if(T->child[i]->size<degree)
        {
            if(i>0 && T->child[i-1]->size>=degree)
            {
                int k;

                //Adjusting number of child's keys and Pointers (i)
                for(k=T->child[i]->size;k>0;k--)
                {
                    T->child[i]->key[k]=T->child[i]->key[k-1];
                    T->child[i]->child[k+1]=T->child[i]->child[k];
                }
                T->child[i]->child[k+1]=T->child[i]->child[k];
                (T->child[i]->size)++;

                T->child[i]->key[0]=T->key[i-1];
                T->child[i]->child[0]=T->child[i-1]->child[T->child[i-1]->size];

                //Adjusting Parent's key
                T->key[i-1]=T->child[i-1]->key[--(T->child[i-1]->size)];
            }
            else if(i<T->size && T->child[i+1]->size>=degree)
            {
                int k;

                //Adjusting number of child's keys and Pointers(i)
                T->child[i]->key[(T->child[i]->size)++]=T->key[i];
                T->child[i]->child[T->child[i]->size]=T->child[i+1]->child[0];

                //Replacing Parent's key
                T->key[i]=T->child[i+1]->key[0];

                //Adjusting adjacent Node keys and pointer (i+1)
                for(k=0;k<T->child[i+1]->size-1;k++)
                {
                    T->child[i+1]->key[k]=T->child[i+1]->key[k+1];
                    T->child[i+1]->child[k]=T->child[i+1]->child[k+1];
                }
                T->child[i+1]->child[k]=T->child[i+1]->child[k+1];
                (T->child[i+1]->size)--;
            }
            else if(i>0)
            {
                Merge(T,i-1);
            }
            else
            {
                Merge(T,i);
            }
        }

        DELETE(T->child[i],n);
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

    height=Height(Btree);
    for(n=height;n>=0;n--)
    {
        PRINT(Btree,height,n);
        cout<<endl;
    }

    cin>>n;
    while(n!=-1)
    {
        DELETE(Btree,n);

        height=Height(Btree);
        for(n=height;n>=0;n--)
        {
            PRINT(Btree,height,n);
            cout<<endl;
        }

        cin>>n;
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
-1
*/

