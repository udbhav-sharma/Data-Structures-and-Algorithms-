#include <iostream>

#define WHITE 0
#define RED 1
#define BLACK 2

using namespace std;

int Edges[100][100];
int Edge_index[100];
int time=0;

class Vertex
{
public:
    int d,f;
    int low;
    int color;
    int parent;
    Vertex()
    {
        color=WHITE;
        f=-1;
        parent=-1;
    }
};

Vertex Vertices[100];

void DFS(int i,int N)
{
    Vertices[i].color=RED;
    Vertices[i].d=++time;
    Vertices[i].low=Vertices[i].d;

    for(;Edge_index[i]<N;Edge_index[i]++)
    {
        if(Edges[i][Edge_index[i]]>0)
        {
            if(Vertices[Edge_index[i]].color==WHITE)
            {
                Vertices[Edge_index[i]].parent=i;
                DFS(Edge_index[i],N);
                Vertices[i].low=min(Vertices[i].low,Vertices[Edge_index[i]].low);
            }
            else if(Vertices[Edge_index[i]].color==RED)
                Vertices[i].low=min(Vertices[i].low,Vertices[Edge_index[i]].d);
        }
    }

    if(Vertices[i].parent==-1)
    {
        int count=0;
        for(int j=0;j<N;j++)
            if(Vertices[j].parent==i)
                count++;
        if(count>1)
            cout<<i<<" ";
    }
    else
    {
        for(int j=0;j<N;j++)
            if(Vertices[j].parent==i && Vertices[j].low>=Vertices[i].d)
            {
                cout<<i<<" ";
                break;
            }
    }
	Vertices[i].color=BLACK;
    Vertices[i].f=++time;
}

int main()
{
    int i,j,N;

    cin>>N;

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            Edges[i][j]=-1;

    while(true)
    {
        cin>>i;
        if(i==-1)
            break;
        cin>>j;
        Edges[i][j]=1;
    }

    DFS(0,N);
    cout<<endl;
    return 0;
}
