
//Given Sorted list of words. Identify the order of alphabets in the language

#include <set>
#include <vector>
#include <iostream>

using namespace std;

#define WHITE 0
#define RED 1
#define BLACK 2

std::vector<string> Words;

class Node
{
	public:
		std::set<int> child;
		char key;
		int color;
		int initial;
		int final;
		Node()
		{
			color=WHITE;
		}
};

std::vector<Node> Vertices;

int getIndex(char x)
{
	for(int i=0;i<Vertices.size();i++)
		if(Vertices[i].key==x)
			return i;
	return -1;
}

int createNode(char x)
{
	Node temp;
	temp.key=x;
	Vertices.push_back(temp);
	return Vertices.size()-1;
}

void addEdge(int i,int j)
{
	Vertices[i].child.insert(j);
}

void insert(char x,char y)
{
	int i=getIndex(x);
	int j=getIndex(y);
	if(i==-1)
		i=createNode(x);
	if(j==-1)
		j=createNode(y);
	addEdge(i,j);
}

void showGraph()
{
	std::set<int>::iterator it;

	cout<<"---------------Graph----------------\n";
	for (int i = 0; i < Vertices.size(); ++i)
	{
		cout<<Vertices[i].key<<"\t";
		for(it=Vertices[i].child.begin();it!=Vertices[i].child.end();it++)
			cout<<Vertices[*it].key<<" ";
		cout<<endl;
	}
}

int num=1;

void Topological_Sort(int index,string &output)
{
	//Doing DFS
	std::set<int>::iterator it;

	Vertices[index].color=RED;
	Vertices[index].initial=num++;

	for(it=Vertices[index].child.begin();it!=Vertices[index].child.end();it++)
		if(Vertices[*it].color==WHITE)
			Topological_Sort(*it,output);

	Vertices[index].final=num++;
	Vertices[index].color=BLACK;
	output=" "+output;
	output=Vertices[index].key+output;
	
}

void generateOutput(string &output)
{
	for(int i=0;i<Vertices.size();i++)
		if(Vertices[i].color==WHITE)
			Topological_Sort(i,output);
}

void formGraph()
{
	for(int i=0;i<Words.size();i++)
		for(int j=i+1;j<Words.size();j++)
			for(int k=0;k<Words[i].length() && k<Words[j].length();k++)
				if(Words[i][k]!=Words[j][k])
				{
					insert(Words[i][k],Words[j][k]);
					break;
				}
}

int main()
{
	string s;
	cin>>s;
	while(s!="-1")
	{
		Words.push_back(s);
		cin>>s;
	}

	formGraph();
	
	showGraph();

	string output="";
	generateOutput(output);
	cout<<"Alphabets Order:\n";
	cout<<output<<endl;
	
	return 0;
}