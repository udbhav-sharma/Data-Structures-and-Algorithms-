#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

#define WHITE 0
#define RED 1
#define BLACK 2

class Vertex
{
public:
    int color,d,f,parent;
    Vertex()
    {
        color=WHITE;
        d=0;
        f=0;
        parent=-1;
    }
};

int Graph[100][100];
Vertex vertices[100];
int time=0;

void DFS_VISIT(int N,int i)
{
    vertices[i].color=RED;
    vertices[i].d=++time;

    for(int j=0;j<N;j++)
        if(Graph[i][j]!=0 && Graph[i][j]!=-1 && vertices[j].color==WHITE)
        {
            vertices[j].parent=i;
            DFS_VISIT(N,j);
        }

    vertices[i].color=BLACK;
    vertices[i].f=++time;
}

void DFS(int N,int i)
{
    for(int j=0;j<N;j++)
        if(vertices[j].color==0)
            DFS_VISIT(N,j);
}

void printDFS(int N)
{
    cout<<"Vertex\tParent\tD\tF\n";
    for(int i=0;i<N;i++)
        printf("%d\t%d\t%d\t%d\n",i,vertices[i].parent,vertices[i].d,vertices[i].f);
}

void DFS_VISIT2(int N,int i)
{
    int j;

    vertices[i].color=1;

    for(j=0;j<N;j++)
        if(Graph[j][i]!=0 && Graph[j][i]!=-1 && vertices[j].color==0)
        {
            vertices[j].parent=i;
            DFS_VISIT2(N,j);
        }

    vertices[i].color=2;
    printf("%d ",i+1);
}

void DFS2(int N)
{
    int j,max,vertex_temp;
    for(j=0;j<N;j++)
    {
        vertices[j].color=WHITE;
        vertices[j].parent=-1;
    }
    while(true)
    {
        max=-1;
        for(j=0;j<N;j++)
            if(max<vertices[j].f && vertices[j].color==WHITE)
            {
                max=vertices[j].f;
                vertex_temp=j;
            }
        if(max==-1)
            break;
        DFS_VISIT2(N,vertex_temp);
        printf("\n");
    }
}

int main()
{
    int N,i,j;
    printf("Enter the number of vertices\n");
    scanf("%d",&N);

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            scanf("%d",&Graph[i][j]);

    DFS(N,0);
    printDFS(N);
    DFS2(N);

    return 0;
}
