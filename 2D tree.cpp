#include <queue>
#include <cmath>
#include <vector>
#include <iomanip>
#include <iostream>
#define infinity 100007

using namespace std;

typedef std::pair<double,double> POINT;

int Xaxis=0;
int Yaxis=1;
int TotalAxis=2;

struct compare
{
   bool operator()(const int& l, const int& r)
   {
       return l > r;
   }
};

class Node
{
    public:
    POINT p;
    double axis;
    double value;
    Node *left,*right;
    Node()
    {
        p.first=0;
        p.second=0;
        left=NULL;
        right=NULL;
    }
    bool IsLeaf()
    {
        return (left==NULL && right==NULL);
    }
};

Node *tree=NULL;
std::vector< POINT > points;
POINT RefQ;
double bestdist;

void Reset();
void PrintTree();
int Height(Node* T);
double Distance(POINT a,POINT b);
void Print(Node* T,int height,int level);
double Minimum( std::vector< POINT > points, int flag);
double FindingMedian(std::vector< POINT > points, int flag);
void Insert( Node* &T, std::vector< POINT > points, int flag );
void Divide(std::vector< POINT > points, double Median, std::vector< POINT > &pointsleft, std::vector< POINT > &pointsright, int flag);

void Reset()
{
    RefQ.first=infinity;
    RefQ.second=infinity;
    bestdist=infinity;
}

double Distance(POINT a,POINT b)
{
    return sqrt(pow((a.first-b.first),2.0)+pow((a.second-b.second),2.0));
}

double Minimum( std::vector< POINT > points, int flag)
{
    double Mini=infinity;
    if(flag==Xaxis)
        for(double i=0;i<points.size();i++)
            if(points[i].first<Mini)
                Mini=points[i].first;
    else
        for(double i=0;i<points.size();i++)
            if(points[i].second<Mini)
                Mini=points[i].second;
    return Mini;
}

void Divide(std::vector< POINT > points, double Median, std::vector< POINT > &pointsleft, std::vector< POINT > &pointsright, int flag)
{
    int n;
    for(double i=0;i<points.size();i++)
    {
        flag==Xaxis ? n=points[i].first : n=points[i].second;
        if(n<Median)
            pointsleft.push_back(points[i]);
        else
            pointsright.push_back(points[i]);
    }
}

double FindingMedian(std::vector< POINT > points, int flag)
{
	std::priority_queue<int> left;
	std::priority_queue<int,std::vector<int>,compare> right;
    double Median=infinity;
	int n;

	for(int i=0;i<points.size();i++)
	{
	    flag==Xaxis ? n=points[i].first : n=points[i].second;
		if(n>Median)
			right.push(n);
		else if(n<Median)
			left.push(n);
		else
		{
			if(left.size()<=right.size())
				left.push(n);
			else
				right.push(n);
		}
		if(((int)left.size())-((int)right.size())>1)
		{
			right.push(left.top());
			left.pop();
		}
		else if(((int)right.size())-((int)left.size())>1)
		{
			left.push(right.top());
			right.pop();
		}
		if((int)left.size()>(int)right.size())
			Median=left.top();
		else if((int)left.size()==(int)right.size())
			Median=(left.top()+right.top())/2.0;
		else
			Median=right.top();
	}
	return Median;
}

void Insert( Node* &T, std::vector< POINT > points, int flag )
{
    if(points.size()==0)
        return;

    T=new Node();
    if(points.size()==1)
    {
        POINT p=points[0];
        T->p.first=p.first;
        T->p.second=p.second;
        return;
    }

    double Median,Mini;
    std::vector< POINT > pointsleft;
    std::vector< POINT > pointsright;

    Median=FindingMedian(points,flag);
    Mini=Minimum(points,flag);

    if(Mini==Median)
        ++Median;

    Divide(points,Median,pointsleft,pointsright,flag);

    T->value=Median;
    T->axis=flag;
    Insert(T->left, pointsleft, (flag+1)%TotalAxis);
    Insert(T->right, pointsright, (flag+1)%TotalAxis);
}

void NearestNeighbourSearch(Node* T,POINT Q)
{
    if(T==NULL)
        return;
    if(T->IsLeaf())
    {
        double dist=Distance(T->p,Q);
        if(dist < bestdist)
        {
            RefQ=T->p;
            bestdist=dist;
        }
    }
    else
    {
        int n;
        T->axis==Xaxis ? n=Q.first:n=Q.second;
        if(n-bestdist<T->value)
            NearestNeighbourSearch(T->left,Q);
        if(n+bestdist>=T->value)
            NearestNeighbourSearch(T->right,Q);
    }
}

int Height(Node* T)
{
    if(T==NULL)
        return 0;
    else
        return(max(Height(T->left),Height(T->right))+1);
}

string PrintAxis(int axis)
{
    if(axis==Xaxis)
        return "X";
    else
        return "Y";
}

void Print(Node* T,int height,int level)
{
    if(T!=NULL)
    {
        Print(T->left,height-1,level);
        if(height==level)
        {
            if(T->IsLeaf())
                cout<<setw(7)<<"("<<T->p.first<<","<<T->p.second<<")";
            else
                cout<<setw(7)<<"("<<PrintAxis(T->axis)<<","<<T->value<<")";
        }
        else
            cout<<setw(7)<<" ";
        Print(T->right,height-1,level);
    }
}

void PrintTree()
{
    int height=Height(tree);
    for(int i=height;i>=0;i--)
    {
        Print(tree,height,i);
        cout<<endl;
    }
}

int main()
{
    double x,y;
    cout<<"Enter Points:\n";
    cin>>x;
    while(x!=-1)
    {
        cin>>y;
        points.push_back(POINT(x,y));
        cin>>x;
    }
    Insert( tree, points, Xaxis );
    PrintTree();

    cout<<"Search:\n";
    POINT Q;
    cin>>x;
    while(x!=-1)
    {
        cin>>y;
        Q.first=x;
        Q.second=y;
        Reset();
        NearestNeighbourSearch( tree,Q);
        cout<<"("<<RefQ.first<<","<<RefQ.second<<")"<<endl;
        cin>>x;
    }
    return 0;
}
/*
5 6
7 8
2 3
7 10
4 5
3 6
-1
*/
