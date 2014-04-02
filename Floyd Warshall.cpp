#include<iostream>
#define infinity 1000000

using namespace std;

int Edges[100][100];
int Parent[100][100];

void print_shortest_path(int i,int j)
{
    cout<<j<<" ";
    if(Parent[i][j]!=i)
        print_shortest_path(i,Parent[i][j]);
    else
        cout<<i<<endl;
}

int main()
{
    int i,j,k,N;

    cin>>N;

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            Edges[i][j]=infinity;
            Parent[i][j]=-1;
        }
        Edges[i][i]=0;
    }

    while(true)
    {
        cin>>i;
        if(i==-1)
            break;
        cin>>j;
        cin>>Edges[i][j];
        Parent[i][j]=i;
    }

    for(k=0;k<N;k++)
    {
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                if(Edges[i][j]>Edges[i][k]+Edges[k][j])
                {
                    Edges[i][j]=Edges[i][k]+Edges[k][j];
                    Parent[i][j]=Parent[k][j];
                }
            }
        }
    }

    cout<<"Print shortest distance matrix:"<<endl;

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            cout<<Edges[i][j]<<" ";
        cout<<endl;
    }

    cin>>i>>j;
    print_shortest_path(i,j);

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
8 6 6
7 6 1
7 8 7
-1
*/
