//For connected graph
#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

#define WHITE 0
#define RED 1
#define BLACK 2

struct Vertex
{
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
queue<int> Q;

void BFS(int N,int i)
{
    vertices[i].color=RED;
    Q.push(i);
    while(!Q.empty())
    {
        i=Q.front();
        Q.pop();
        vertices[i].color=BLACK;

        for(int j=0;j<N;j++)
            if(Graph[i][j]!=0 && Graph[i][j]!=-1 && vertices[j].color==WHITE)
            {
                Q.push(j);
                vertices[j].parent=i;
            }
    }
}

void printBFS(int N)
{
	cout<<"Vertex\tParent\n";
    for(int i=0;i<N;i++)
        printf("%d\t%d\n",i,vertices[i].parent);
}

int main()
{
    int N,i,j;
    printf("Enter the number of vertices\n");
    scanf("%d",&N);

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            scanf("%d",&Graph[i][j]);

    BFS(N,0);
    printBFS(N);

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
