/*https://www.hackerrank.com/challenges/cut-the-tree*/
#include <cmath>
#include <queue>
#include <iostream>

using namespace std;

#define maxn 100005
#define infinity 1000000007
#define WHITE 1
#define GREY 2
#define BLACK 3

class vertex
{
	public:
		int key;
		int parent;
		int color;
		long long treeSum;
		long long parentTreeSum;
		vertex()
		{
			parent=-1;
			color=WHITE;
			treeSum=0;
			parentTreeSum=0;
		}
};

vertex vertices[maxn];
queue<int> vertexorder;
vector< vector<int> >Edges(maxn);
long long treeDiff=infinity;

long long min(long long x,long long y)
{
	return x<y?x:y;
}

void BFS()
{
	int i=1;
	vertexorder.push(i);
	while(!vertexorder.empty())
	{
		i=vertexorder.front();
		for(int j=0;j<Edges[i].size();)
		{
			if(vertices[Edges[i][j]].color==WHITE)
			{
				vertices[Edges[i][j]].color=GREY;
				vertices[Edges[i][j]].parent=i;
				vertexorder.push(Edges[i][j]);
				j++;
			}
			else
			{
				Edges[i].erase(Edges[i].begin()+j);
			}
		}
		vertices[i].color=BLACK;
		vertexorder.pop();
	}
}

void PrintEdges(int N)
{
	for(int i=1;i<=N;i++)
	{
		cout<<i<<":\t";
		for(int j=0;j<Edges[i].size();j++)
			cout<<Edges[i][j]<<", ";
		cout<<endl;
	}
}

void calculateSum(int i)
{
	vertices[i].treeSum=vertices[i].key;
	for(int j=0;j<Edges[i].size();j++)
	{
		calculateSum(Edges[i][j]);
		vertices[i].treeSum+=vertices[Edges[i][j]].treeSum;
	}
}

void calculateParentTreeSum(int i,int sum)
{
	vertices[i].parentTreeSum=sum-vertices[i].treeSum;
	treeDiff=min(treeDiff,abs(vertices[i].treeSum - vertices[i].parentTreeSum));
	for(int j=0;j<Edges[i].size();j++)
		calculateParentTreeSum(Edges[i][j],sum);
}

void showSum(int N)
{
	for(int i=1;i<=N;i++)
		cout<<i<<":\t"<<vertices[i].treeSum<<"\t"<<vertices[i].parentTreeSum<<endl;
	return;
}

int main()
{
	int N,x,y;
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>vertices[i].key;
	}
	for(int i=1;i<N;i++)
	{
		cin>>x>>y;
		Edges[x].push_back(y);
		Edges[y].push_back(x);
	}
	BFS();
	//PrintEdges(N);
	calculateSum(1);
	calculateParentTreeSum(1,vertices[1].treeSum);
	//showSum(N);
	cout<<treeDiff<<endl;
	return 0;
}