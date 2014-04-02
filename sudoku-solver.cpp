#include <iostream>
#include <cstring>

using namespace std;

int Sudoku[9][9]={{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

struct row_col{
	int i,j;
};


void print_sol()
{
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
			cout<<Sudoku[i][j]<<"\t";
		cout<<endl;
	}	
}

struct row_col next(int i,int j)
{
	struct row_col T;
	T.i=-1;
	T.j=-1;

	for(;j<9;j++)
		if(Sudoku[i][j]==0)
		{
			T.i=i;
			T.j=j;
			return T;
		}

	for(i++;i<9;i++)
		for(j=0;j<9;j++)
			if(Sudoku[i][j]==0)
			{
				T.i=i;
				T.j=j;
				return T;
			}
	return T;
}

bool isSafe(const int i,const int j,int k)
{
	int count[10];
	//Check for row
	
	memset(count,0,sizeof(count));
	for(int m=0;m<9;m++)
	{
		count[Sudoku[i][m]]++;
		if(count[Sudoku[i][m]]>1 && Sudoku[i][m]!=0)
			return false;
	}

	//Check for columm
	memset(count,0,sizeof(count));
	for(int m=0;m<9;m++)
	{
		count[Sudoku[m][j]]++;
		if(count[Sudoku[m][j]]>1 && Sudoku[m][j]!=0)
			return false;
	}

	//Check for 3*3 Square
	int m=i/3;
	int n=j/3;
	memset(count,0,sizeof(count));
	for(;m<i/3+3;m++)
		for(;n<j/3+3;n++)
		{
			count[Sudoku[m][n]]++;
			if(count[Sudoku[m][n]]>1 && Sudoku[m][n]!=0)
				return false;
		}

	return true;

}

bool Solve_sudoku(const struct row_col T)
{
	if(T.i==-1 && T.j==-1)
		return true;

	int k=1;
	while(k<=9)
	{
		Sudoku[T.i][T.j]=k;
		if(isSafe(T.i,T.j,k))
			if(Solve_sudoku(next(T.i,T.j)))
				return true;
		Sudoku[T.i][T.j]=0;
		k++;
	}

	return false;
}

int main()
{
	int i,j;
	//Input
	// cout<<"Enter the Sudoku Matrix\n";

	// for(i=0;i<9;i++)
	// 	for(j=0;j<9;j++)
	// 		cin>>Sudoku[i][j];

	if(Solve_sudoku(next(0,0)))
		print_sol();
	else
		cout<<"No Solution exists\n";

	return 0;
}