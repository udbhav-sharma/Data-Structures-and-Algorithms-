#include <iostream>
#include <list>
#include <stack>
#include <limits.h>
#define NINF INT_MIN
using namespace std;

class AdjListNode
{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w)  { v = _v;  weight = _w;}
    int getV()       {  return v;  }
    int getWeight()  {  return weight; }
};

class Graph
{
    int V;
    list<AdjListNode> *adj;

    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);

    void addEdge(int u, int v, int weight);

    void longestPath(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}

void Graph::addEdge(int u, int v, int weight)
{
    AdjListNode node(v, weight);
    adj[u].push_back(node);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;

    list<AdjListNode>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        AdjListNode node = *i;
        if (!visited[node.getV()])
            topologicalSortUtil(node.getV(), visited, Stack);
    }

    Stack.push(v);
}

void Graph::longestPath(int s)
{
    stack<int> Stack;
    int dist[V];

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);

    for (int i = 0; i < V; i++)
        dist[i] = NINF;
    dist[s] = 0;
    while (Stack.empty() == false)
    {
        int u = Stack.top();
        Stack.pop();
        list<AdjListNode>::iterator i;
        if (dist[u] != NINF)
        {
          for (i = adj[u].begin(); i != adj[u].end(); ++i)
             if (dist[i->getV()] < dist[u] + i->getWeight())
                dist[i->getV()] = dist[u] + i->getWeight();
        }
    }

    cout << dist[V-1];
}

int main()
{

    int N,x,i,j,k,m;
    string s;
    cin>>N;
    Graph g(N+1);

    for(x=0;x<N;x++)
    {
        cin>>i>>m;
        cin>>s;
        if(s=="E")
            j=N;
        else
        {
            j=0;
            for(int y=0;y<s.length();y++)
                j=j*10+(s[y]-'0');
        }
        cin>>s;
        if(s=="E")
            k=N;
        else
        {
            k=0;
            for(int y=0;y<s.length();y++)
                k=k*10+(s[y]-'0');
        }
        g.addEdge(i,j,m);
        g.addEdge(i, k, m);
    }

        g.longestPath(0);

    return 0;
}
