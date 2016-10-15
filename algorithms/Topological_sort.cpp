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
stack<int> S;
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
    S.push(i);
}

void DFS(int N,int i)
{
    for(int j=0;j<N;j++)
        if(vertices[j].color==WHITE)
            DFS_VISIT(N,j);
}

void PrintTopologicalSort(int N)
{
    while(!S.empty())
    {
        printf("%d\n",S.top()+1);
        S.pop();
    }
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
    PrintTopologicalSort(N);

    return 0;
}
/*
9
0 1 -1 -1 1 -1 -1 -1 -1
-1 0 1 -1 1 -1 -1 -1 -1
-1 -1 0 -1 -1 -1 -1 -1 1
-1 -1 1 0 -1 -1 -1 1 -1
-1 -1 -1 -1 0 -1 -1 -1 -1
-1 -1 -1 -1 1 0 -1 -1 -1
-1 -1 -1 -1 -1 -1 0 -1 -1
-1 -1 -1 -1 -1 -1 -1 0 1
-1 -1 -1 -1 -1 -1 -1 -1 0
*/
