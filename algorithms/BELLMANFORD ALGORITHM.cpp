#include <iostream>

#define infinity 10000007

using namespace std;

struct Edge
{
    int u,v,c;
};

Edge edges[1000];
int VERTEX_D[100];
int VERTEX_P[100];

void INITIALIZE_VERTEX(int u,int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        VERTEX_D[i]=infinity;
        VERTEX_P[i]=-1;
    }
    VERTEX_D[u]=0;
}

void RELAXEDGE(Edge edge)
{
    if(VERTEX_D[edge.v]>VERTEX_D[edge.u]+edge.c)
    {
        VERTEX_D[edge.v]=VERTEX_D[edge.u]+edge.c;
        VERTEX_P[edge.v]=edge.u;
    }
}

void PRINT_SHORTEST_PATH(int v)
{
    if(VERTEX_P[v]!=-1)
        PRINT_SHORTEST_PATH(VERTEX_P[v]);
    cout<<v<<" ";
}

int main()
{
    int N,i,j,k;
    bool flag;
    cin>>N;

    k=0;
    while(true)
    {
        cin>>i;
        if(i==-1)
            break;
        cin>>j;
        edges[k].u=i;
        edges[k].v=j;
        cin>>edges[k++].c;
    }

    int u,v;

    cout<<"Enter the starting and ending vertex";
    cin>>u>>v;

    //Algorithm beign
    INITIALIZE_VERTEX(u,N);

    for(i=1;i<N;i++)
        for(j=0;j<k;j++)
            RELAXEDGE(edges[j]);

    flag=true;
    for(i=0;i<k;i++)
        if(VERTEX_D[edges[i].v]>VERTEX_D[edges[i].u]+edges[i].c)
        {
            flag=false;
            break;
        }

    if(flag)
    {
        PRINT_SHORTEST_PATH(v);
        cout<<"\nShortest Distance is: "<<VERTEX_D[v];
    }

    else
        cout<<"Negative weight cycle present";

    cout<<endl;
    return 0;
}
/*
5
0 1 2
0 3 4
1 3 3
1 2 2
3 4 2
2 4 1
-1
*/
