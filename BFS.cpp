#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

struct Vertex
{
    int color,d,f,parent;
};

int Graph[100][100];
Vertex vertices[100];
queue<int> Q;

void BFS(int N,int i)
{
    int j;
    for(j=0;j<N;j++)
    {
        vertices[j].color=0;
        vertices[j].d=-1;
        vertices[j].parent=-1;
    }
    vertices[i].color=1;
    Q.push(i);
    while(!Q.empty())
    {
        i=Q.front();
        vertices[i].color=2;
        Q.pop();

        for(j=0;j<N;j++)
            if(Graph[i][j]!=0 && vertices[j].color==0)
            {
                Q.push(j);
                vertices[j].color=1;
                vertices[j].parent=i;
            }
    }
}

void printBFS(int N)
{
    int i;
    for(i=0;i<N;i++)
        printf("%d %d\n",i,vertices[i].parent);
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
