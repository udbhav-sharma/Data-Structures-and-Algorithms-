#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

struct Edge
{
    int u,v,c;
    bool operator< (const Edge& that) const
    {
        return this->c > that.c;
    }
} MinimumSpanningTree[100];

int set_vertices[100];
int rank_vertices[100];

int find_set(int u)
{
    if(u!=set_vertices[u])
        u=find_set(set_vertices[u]);
    return u;
}

void union_set(int u,int v)
{
    u=find_set(u);
    v=find_set(v);
    if(rank_vertices[u]>rank_vertices[v])
        set_vertices[v]=u;
    else
    {
        set_vertices[u]=v;
        if(rank_vertices[u]==rank_vertices[v])
            rank_vertices[v]++;
    }
}

int main()
{
    priority_queue<Edge> a;
    Edge edge;
    int N,i,j,k;
    cout<<"Enter the number of vertices\n";
    cin>>N;

    memset(rank_vertices,0,sizeof(rank_vertices));

    for(i=0;i<N;i++)
        set_vertices[i]=i;

    cout<<"Enter the edges. For ending enter -1\n";

    while(true)
    {
        cin>>edge.u;
        if(edge.u==-1)
            break;
        cin>>edge.v>>edge.c;
        a.push(edge);
    }

    //Creating a Spanning Tree
    k=0;
    while(!a.empty() && k<=N)
    {
        edge=a.top();
        a.pop();
        if(find_set(edge.u)!=find_set(edge.v))
        {
            union_set(edge.u,edge.v);
            MinimumSpanningTree[k]=edge;
            k++;
        }
    }

    //printing Spanning tree's edges
    cout<<"Minimum Spanning Tree edges are:\n";
    for(i=0;i<N-1;i++)
    {
        cout<<MinimumSpanningTree[i].u<<" "<<MinimumSpanningTree[i].v<<" "<<MinimumSpanningTree[i].c<<endl;
    }

    return 0;
}
/*
0 1 4
0 7 8
1 7 11
1 2 8
2 3 7
3 4 9
3 5 14
4 5 10
2 5 4
6 5 2
8 2 2
1 0 4
7 0 8
7 1 11
2 1 8
3 2 7
4 3 9
5 3 14
5 4 10
5 2 4
5 6 2
2 8 2
8 6 6
7 6 1
7 8 7
6 8 6
6 7 1
8 7 7
-1
*/
