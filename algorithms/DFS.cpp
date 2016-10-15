#include <iostream>
#include <stdio.h>

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
        if(vertices[j].color==WHITE)
            DFS_VISIT(N,j);
}

void printDFS(int N)
{
    cout<<"Vertex\tParent\tD\tF\n";
    for(int i=0;i<N;i++)
        printf("%d\t%d\t%d\t%d\n",i,vertices[i].parent,vertices[i].d,vertices[i].f);
}

int main()
{
    int N;
    printf("Enter the number of vertices\n");
    scanf("%d",&N);

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&Graph[i][j]);

    DFS(N,0);
    printDFS(N);

    return 0;
}
/*
5
0 1 -1 -1 -1
-1 0 -1 1 1
-1 -1 0 -1 -1
-1 -1 -1 0 -1
-1 -1 1 -1 0
*/
