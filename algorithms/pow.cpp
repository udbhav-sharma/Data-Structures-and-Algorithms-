#include <iostream>

using namespace std;

long long power(long long a, long long b)
{
	long long ret=1;
	while(b)
	{
		if(b&1)
			ret*=a;
		a=a*a;
		b/=2;
	}
	return ret;
}

int main()
{
	int a,b;
	while(1)
	{
		cout<<"a:\t";
		cin>>a;
		cout<<"b:\t";
		cin>>b;
		cout<<power(a,b)<<endl;
	}
	return 0;
}