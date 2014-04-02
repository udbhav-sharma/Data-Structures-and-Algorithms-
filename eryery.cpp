#include<iostream>
#include<math.h>
#include<cstring>

using namespace std;

struct input
{
    double t;
    int n;
};

double square(double n)
{
    return n*n;
}

double cube(double n)
{
    return n*square(n);
}

long long power(long long n,long long x)
{
    if(n==0)
        return 1;
    if(n==1)
        return x;
    if(n%2==0)
    {
        return power(n/2,x*x);
    }
    return x*power(n/2,x*x);
}

void test(input testcase[],int N)
{
    double error[8];
    memset(error,0,sizeof(error));

    for(int i=0;i<N;i++)
    {
        error[0]+=square(testcase[i].t-1);
        error[1]+=square(testcase[i].t-log(testcase[i].n)/log(2));
        error[2]+=square(testcase[i].t-testcase[i].n);
        error[3]+=square(testcase[i].t-testcase[i].n*log(testcase[i].n)/log(2));
        error[4]+=square(testcase[i].t-square(testcase[i].n));
        error[5]+=square(testcase[i].t-square(testcase[i].n)*log(testcase[i].n)/log(2));
        error[6]+=square(testcase[i].t-cube(testcase[i].n));
        error[7]+=square(testcase[i].t-power(testcase[i].n,2));
    }

    double min=error[0];
    int ans=0;
    for(int i=1;i<8;i++)
        if(min>error[i]) ans=i,min=error[i];

    switch(ans)
    {
    case 0:
        cout<<"O(1)\n";
        break;
    case 1:
        cout<<"O(log n)\n";
        break;
    case 2:
        cout<<"O(n)\n";
        break;
    case 3:
        cout<<"O(n log n)\n";
        break;
    case 4:
        cout<<"O(n^2)\n";
        break;
    case 5:
        cout<<"O(n^2 log n)\n";
        break;
    case 6:
        cout<<"O(n^3)\n";
        break;
    case 7:
        cout<<"O(2^n)\n";
    }
}


int main()
{
    int N,i;
    cin>>N;

    input testcase[N];
    for(i=0;i<N;i++)
        cin>>testcase[i].n>>testcase[i].t;

    test(testcase,N);
    return 0;
}
