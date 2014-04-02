#include<iostream>
#define infinity 1000007
#define WHITE 0
#define GREY 1
#define BLACK 2

using namespace std;

struct Vertex
{
    int dist;
    int parent;
    int Vertex_index;
    Vertex()
    {
        dist=infinity;
        parent=-1;
    }
};

int color[100];
int vertices[100];
int edge[100][100];
Vertex A[100];
Vertex B[100];

class Heap
{
    public:
        int size;

        Heap()
        {
            size=0;
        }

        void Insert(Vertex v)
        {
            A[++size]=v;
            vertices[A[size].Vertex_index]=size;
        }

        bool Empty()
        {
            return (size<=0);
        }

        Vertex Extract_Min()
        {
            cout<<"Extract_Min Executed.\n";
            Vertex min=A[1];
            A[1]=A[size];
            vertices[A[1].Vertex_index]=1;
            size--;
            Min_Heapify(1);
            return min;
        }

        void Increase_Key(int i,int c)
        {
            A[i].dist=c;
            while(i>1 && A[i].dist<A[i/2].dist)
            {
                cout<<"Increase Key executed.\n";
                swap(A[i],A[i/2]);
                vertices[A[i].Vertex_index]=i;
                vertices[A[i/2].Vertex_index]=i/2;
                i=i/2;
            }
        }

        void swap(Vertex& i,Vertex& j)
        {
            Vertex t=i;
            i=j;
            j=t;
        }

        void Min_Heapify(int i)
        {
            cout<<"Min_Heapify executed.\n";
            int left=2*i;
            int right=2*i+1;
            int smallest;

            if(left<=size && A[left].dist<A[i].dist)
                smallest=left;
            else
                smallest=i;
            if(right<=size && A[right].dist<A[smallest].dist)
                smallest=right;
            if(smallest!=i)
            {
                swap(A[smallest],A[i]);
                vertices[A[smallest].Vertex_index]=smallest;
                vertices[A[i].Vertex_index]=i;
                Min_Heapify(smallest);
            }
        }

};

Heap H;

void RELAX_EDGE(int u,int v,int c)
{
    cout<<"Relax edge started.\n";

    if(A[vertices[v]].dist>c)
    {
        cout<<"Relax Edge Executed.\n";
        A[vertices[v]].parent=u;
        H.Increase_Key(vertices[v],c);
    }
}

void Print_Shortest_Path(int v)
{
    if(B[v].parent!=-1)
        Print_Shortest_Path(B[v].parent);
    cout<<v<<" ";
}

int main()
{
    int i,j,N;

    cout<<"Enter the Number of vertices:\n";
    cin>>N;

    Vertex temp_vertex;

    cout<<"Enter the Edges:\n";

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            edge[i][j]=-1;

    while(true)
    {
        cin>>i;
        if(i==-1)
            break;
        cin>>j;
        cin>>edge[i][j];
    }

    int u,v;
    cout<<"Enter the Starting and Ending vertex:\n";
    cin>>u>>v;

    temp_vertex.dist=0;
    temp_vertex.Vertex_index=u;
    H.Insert(temp_vertex);

    for(i=0;i<N;i++)
    {
        if(i==u)
            continue;
        temp_vertex.dist=infinity;
        temp_vertex.Vertex_index=i;
        H.Insert(temp_vertex);
    }

    while(H.size!=0)
    {
        temp_vertex=H.Extract_Min();
        u=temp_vertex.Vertex_index;
        B[u]=temp_vertex;

        for(j=0;j<N;j++)
            if(edge[u][j]>0 && color[j]==WHITE)
                RELAX_EDGE(u,j,temp_vertex.dist+edge[u][j]);
        color[u]=BLACK;
    }

    Print_Shortest_Path(v);

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
