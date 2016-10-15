#include <stack>
#include <iostream>

#define WHITE 0
#define GREY 1
#define BLACK 2

#define infinity 1000007

using namespace std;

int Edge[100][100];
int time=0;

struct VERTEX
{
    int d,f;
    int color;
    int parent;
    int dist;
    VERTEX()
    {
        dist=infinity;
        parent=-1;
        color=WHITE;
    }

    bool operator<(const VERTEX& that)const
    {
        return this->f>that.f;
    }
};

VERTEX vertices[100];
stack<int> s;

void Topological_Sort(int i,int N)
{
    int j;
    vertices[i].color==GREY;
    vertices[i].d=time++;

    for(j=0;j<N;j++)
    {
        if(Edge[i][j]>0 && vertices[j].color==WHITE)
        {
            vertices[j].parent=i;
            Topological_Sort(j,N);
        }
    }

    vertices[i].f=time++;
    vertices[i].color=BLACK;
    s.push(i);
}

void RELAXEDGE(int u,int v,int c)
{
    if(vertices[v].dist>vertices[u].dist+c)
    {
        vertices[v].dist=vertices[u].dist+c;
        vertices[v].parent=u;
    }
}

void PRINT_SHORTEST_PATH(int v)
{
    if(vertices[v].parent!=-1)
        PRINT_SHORTEST_PATH(vertices[v].parent);
    cout<<v<<" ";
}

int main()
{
    int N,i,j;

    cout<<"Enter the number of vertices.\n";
    cin>>N;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            Edge[i][j]=-1;

    cout<<"Enter the Edges:\n";
    while(true)
    {
        cin>>i;
        if(i==-1)
            break;
        cin>>j;
        cin>>Edge[i][j];
    }

    int u,v;

    cout<<"Enter the Starting and Ending vertices:\n";
    cin>>u>>v;

    Topological_Sort(u,N);

    vertices[u].dist=0;

    while(!s.empty())
    {
        i=s.top();
        for(j=0;j<N;j++)
            if(Edge[i][j]>0)
                RELAXEDGE(i,j,Edge[i][j]);
        s.pop();
    }

    PRINT_SHORTEST_PATH(v);
    cout<<"Shortest Distance is: "<<vertices[v].dist<<endl;

    return 0;
}
