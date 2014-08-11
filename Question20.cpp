/*https://www.hackerrank.com/challenges/the-quickest-way-up*/

#include <map>
#include <vector>
#include <iostream>
#define infinity 1000007

using namespace std;

typedef pair<int,int> pi;
std::vector<int> board;
std::vector<bool> visited;

struct compare
{
	bool operator()(const pi &l, const pi &r )
	{
		return l>r;
	}
};

map<int,int> snakes;
map<int,int> ladders;
int snakes_size,ladders_size;

map<int,int> input(int input_size)
{
	int start,end;
	char comma;
	map<int,int> input_map;
	for(int i=0;i<input_size;i++)
	{
		cin>>start>>comma>>end;
		input_map.insert(std::pair<int,int>(start,end));
	}
	return input_map;
}

int minimum(std::vector<int> board, std::vector<bool> visited)
{
	int min=infinity;
	int min_index=-1;
	for(int i=1;i<=100;i++)
		if(!visited[i] && min > board[i])
		{
			min=board[i];
			min_index=i;
		}
	return min_index;
}

void update(int i, int j,int k)
{
	board[j]=min(board[i]+k,board[j]);
}

void printMatrix()
{
	for(int i=1;i<=100;i++)
		cout<<i<<"\t"<<board[i]<<endl;
}

void clean()
{
	ladders.clear();
	snakes.clear();
	board.clear();
	visited.clear();
	ladders_size=0;
	snakes_size=0;
	for(int i=0;i<=100;i++)
	{
		board.push_back(infinity);
		visited.push_back(false);
	}
}

int main()
{
	int test_cases;
	char comma;
	cin>>test_cases;
	while(test_cases--)
	{
		clean();
		cin>>ladders_size>>comma>>snakes_size;

		ladders=input(ladders_size);
		snakes=input(snakes_size);

		board[1]=0;

		for(int i=1;i<=100;i++)
		{
			map<int,int>::iterator it;
			int j=minimum(board,visited);

			it=snakes.find(j);
			if(it!=snakes.end())
				update(j,it->second,0);

			else
			{
				for(int k=1;k<=6;k++)
					update(j,j+k,1);

				it=ladders.find(j);
				if(it!=ladders.end())
					update(j,it->second,0);
			}
			visited[j]=true;
		}
		//printMatrix();
		cout<<board[100]<<endl;
	}

	return 0;
}
/*
3
3,7
32,62 42,68 12,98
95,13 97,25 93,37 79,27 75,19 49,47 67,17
5,8
32,62 44,66 22,58 34,60 2,90
85,7 63,31 87,13 75,11 89,33 57,5 71,15 55,25
4,9
8,52 6,80 26,42 2,72
51,19 39,11 37,29 81,3 59,5 79,23 53,7 43,33 77,21
*/
