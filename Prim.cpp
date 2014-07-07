#include <iostream>
#define infinity 1<<30

using namespace std;

class Vertex
{
public:
    int parent,d,color;
    Vertex()
    {
        d=infinity;
        color=0;
        parent=-1;
    }
};

int Graph[100][100];
int N;
Vertex vertices[100];

void PRINT_PRIM()
{
    int i;
    cout<<"Following are the edges in the Minimum Spanning Tree:\n";

    for(i=0;i<N;i++)
        cout<<i<<" "<<vertices[i].parent<<" "<<vertices[i].d<<" "<<Graph[i][vertices[i].parent]<<endl;
}

void PRIM()
{
    int i,j,k,min_dist,min_vertex;

    i=0;
    vertices[i].d=0;
    for(k=0;k<N;k++)
    {
        cout<<endl<<"i="<<i<<" k="<<k<<endl;
        min_dist=infinity;
        vertices[i].color=1;
        for(j=0;j<N;j++)
        {
            if(vertices[j].color!=0)
            {
                continue;
            }
            if(Graph[i][j]>0)
            {
                if(vertices[j].d>Graph[i][j])
                {
                    vertices[j].parent=i;
                    vertices[j].d=Graph[i][j];
                }
            }
            if(min_dist>vertices[j].d)
            {
                min_dist=vertices[j].d;
                min_vertex=j;
            }
        }
        vertices[i].color=2;
        i=min_vertex;
    }
}

int main()
{
    int i,j,k;
    cout<<"Enter the number of Vertices:\n";
    cin>>N;

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            Graph[i][j]=-1;
        Graph[i][i]=0;
    }

    while(true)
    {
        cin>>i;
        if(i==-1)
            break;
        cin>>j>>k;
        Graph[i][j]=k;
    }

    PRIM();

    PRINT_PRIM();

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
