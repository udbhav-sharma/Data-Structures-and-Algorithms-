/*
Implement LRU cache of size 10 which can store Key, Value pair. (get(key) & put(key,value) methods) 
- If we try to add 11th element, the least recently used element should get removed. 
- If key already present, overwrite it and mark it as most recently used.
*/

#include <iostream>
#define maxn 10

using namespace std;

class abc
{
	public:
		int key;
		int value;
		int time;
} cache[maxn];

int size=0;

int Least_Recently_Used()
{
	int max=-1;
	int max_index=-1;
	for(int i=0;i<maxn;i++)
		if(max<cache[i].time)
		{
			max=cache[i].time;
			max_index=i;
		}
	return max_index;
}

void update_access_time(int j)
{
	for(int i=0;i<maxn;i++)
		cache[i].time++;
	cache[j].time=0;
}

int get(int key)
{
	for(int i=0;i<10;i++)
		if(cache[i].key==key)
		{
			update_access_time(i);
			return cache[i].value;
		}
	return -1;
}

void put(int key,int value)
{
	if(size<10)
	{
		cache[size].key=key;
		cache[size++].value=value;
		update_access_time(size-1);
	}
	else
	{
		int i=Least_Recently_Used();
		cache[i].key=key;
		cache[i].value=value;
		update_access_time(i);
	}
}

void showCache()
{
	cout<<"Key\tValue\tTime\t\n";
	for(int i=0;i<size;i++)
		cout<<cache[i].key<<"\t"<<cache[i].value<<"\t"<<cache[i].time<<endl;
}

int main()
{
	int n,k;
	int key,value;

	cout<<"1: Get\n2: Put\n";
	while(1)
	{
		cin>>n;
		switch (n)
		{
			case 1:
				cin>>key;
				k=get(key);
				if(k==-1)
					cout<<"key isn't cached\n";
				else
					cout<<k<<endl;
				break;
			case 2:
				cin>>key>>value;
				put(key,value);
		}
		showCache();
	}
	return 0;
}