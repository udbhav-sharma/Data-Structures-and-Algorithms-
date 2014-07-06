#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int Edges[100][100];
int Edge_index[100];
queue<int> q;

void DFS(int i,int N)
{
    q.push(i);

    for(;Edge_index[i]<N;Edge_index[i]++)
        if(Edges[i][Edge_index[i]]>0)
        {
            Edges[i][Edge_index[i]]=-1;
            Edges[Edge_index[i]][i]=-1;
            DFS(Edge_index[i]++,N);
            break;
        }
}

int main()
{
    int i,j,N;
    cin>>N;

    memset(Edge_index,0,sizeof(Edge_index));

    //Input
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            Edges[i][j]=-1;

    while(true)
    {
        cin>>i;
        if(i==-1)
            break;
        cin>>j;
        Edges[i][j]=1;
        Edges[j][i]=1;
    }

    DFS(4,N);

    while(!q.empty())
    {
        i=q.front();
        for(;Edge_index[i]<N;Edge_index[i]++)
            if(Edges[i][Edge_index[i]]>0)
            {
                j=q.size();
                DFS(Edge_index[i],N);
                while(j--)
                {
                    q.push(q.front());
                    q.pop();
                }
            }
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}

/*
0 2
0 3
2 3
1 2
1 7
7 8
2 5
2 6
2 8
5 8
6 8
8 9
8 11
11 9
3 6
3 4
3 9
6 9
4 9
9 10
3 10
*/
