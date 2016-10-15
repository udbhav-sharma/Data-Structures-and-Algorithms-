#include <iostream>
#include <cmath>
#include <map>
#define maxs 30
#define maxc 1000

using namespace std;

struct accessPoints
{
	int x,y;
	int limit;
};

struct computers
{
	int x,y;
	double finalDist;
	multimap<double,int> dist;
	multimap<double,int>::reverse_iterator position;
	bool flag;
	computers()
	{
		flag=false;
		finalDist=-1;
	}
};

multimap<double,int> globalDist;
accessPoints AP[maxs];
computers arrivingSystem[maxc];

void printFinalDist(int C);
void CalculateDist(int i,int S)
{
	double d;
	for(int j=0;j<S;j++)
	{
		d=sqrt(pow(arrivingSystem[i].x-AP[j].x,2)+pow(arrivingSystem[i].y-AP[j].y,2));
		arrivingSystem[i].dist.insert(std::pair<double,int>(d,j));
	}
}

void FormGlobalDist(int i)
{
	multimap<double,int>::iterator it;
	for(it=arrivingSystem[i].dist.begin();it!=arrivingSystem[i].dist.end();it++)
	{
		globalDist.insert(std::pair<double,int>(it->first,i));
	}
}

void InitializePosition(int C)
{
	for(int i=0;i<C;i++)
		arrivingSystem[i].position=arrivingSystem[i].dist.rbegin();
}

void FormSolution(int C)
{
	multimap<double,int>::reverse_iterator it,it2;
	it=globalDist.rbegin();
	while(it!=globalDist.rend())
	{
		int i=it->second;
		it2=arrivingSystem[i].position;
		it2++;
		
		if(it2==arrivingSystem[i].dist.rend())
		{
			it++;
			continue;
		}
		
		int ap_temp=(it2)->second;
		if((AP[ap_temp].limit-1)>=0)
		{
			AP[ap_temp].limit--;
			it2=it;
			if(arrivingSystem[i].flag)
			{
				if(++(AP[arrivingSystem[i].position->second].limit)==1)
					it=globalDist.rbegin();
				else
					it++;
			}
			else
			{
				arrivingSystem[i].flag=true;
				it++;
			}
			globalDist.erase(--(it2.base()));
			arrivingSystem[i].position++;
			arrivingSystem[i].finalDist=arrivingSystem[i].position->first;
		}
		else
		{
			if(arrivingSystem[i].finalDist==-1)
				arrivingSystem[i].finalDist=it->first;
			it++;
		}
		//printFinalDist(C);
	}
}

void Clean(int C)
{
	globalDist.clear();
	for(int i=0;i<C;i++)
		arrivingSystem[i].dist.clear();
}

void printMultiMap(multimap<double,int> m)
{
	multimap<double,int>::reverse_iterator it;
	for(it=m.rbegin();it!=m.rend();it++)
	{
		cout<<it->first<<"\t"<<it->second<<endl;
	}
}

void printFinalDist(int C)
{
	cout<<"Final Distance are:\n";
	for(int i=0;i<C;i++)
		cout<<"("<<arrivingSystem[i].x<<","<<arrivingSystem[i].y<<")"<<"\t"<<arrivingSystem[i].finalDist<<endl;
}

int main()
{
	int T,S,C;

	cin>>T;
	while(T--)
	{
		cin>>S>>C;
		for(int i=0;i<S;i++)
			cin>>AP[i].x>>AP[i].y>>AP[i].limit;
		for(int i=0;i<C;i++)
		{
			cin>>arrivingSystem[i].x>>arrivingSystem[i].y;
			CalculateDist(i,S);
			FormGlobalDist(i);
		}
		
		//Printing for each new computer distance list
		/*for(int i=0;i<C;i++)
		{
			cout<<"For I="<<i<<endl;
			printMultiMap(arrivingSystem[i].dist);
		}*/

		//Printing global distance list
		/*cout<<"Global List:\n";
		printMultiMap(globalDist);*/
			
		InitializePosition(C);
		FormSolution(C);
		printFinalDist(C);
		Clean(C);
	}
	return 0;
}