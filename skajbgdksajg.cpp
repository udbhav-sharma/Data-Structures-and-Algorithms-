#include<iostream>
#include<iostream>
#include<stdio.h>
#include<set>
#include<cstring>
#include<math.h>
#define limit 1000005

using namespace std;

int root = ceil(sqrt(limit));
bool sieve[limit];

void generate_prime()
{
 //Create the various different variables required
 for (int z = 0; z < limit; z++)
    sieve[z] = false; //Not all compilers have false as the default boolean value
 for (int x = 1; x <= root; x++)
 {
    for (int y = 1; y <= root; y++)
    {
    //Main part of Sieve of Atkin
        int n = (4*x*x)+(y*y);
        if (n <= limit && (n % 12 == 1 || n % 12 == 5))
            sieve[n] ^= true;
        n = (3*x*x)+(y*y);
        if (n <= limit && n % 12 == 7)
            sieve[n] ^= true;
        n = (3*x*x)-(y*y);
        if (x > y && n <= limit && n % 12 == 11)
            sieve[n] ^= true;
    }
 }
 //Mark all multiples of squares as non-prime
 for (int r = 5; r <= root; r++)
    if (sieve[r])
        for (int i = r*r; i < limit; i += r*r)
            sieve[i] = false;
}
int prime[limit];
int count[limit];

int main()
{
    int T,P,i,j;
    long long ans;
    set<int> d;
    set<int>:: iterator it;
    double temp;
    cin>>T;

    generate_prime();
    sieve[2]=true;
    sieve[3]=true;
    for(i=0,j=0;i<limit;i++)
        if(sieve[i])
            prime[j++]=i;

    while(T--)
    {
        cin>>P;
        for(i=2;i<=P;i++)
        {
            for(j=0;j<=i;j++)
                if(i%prime[j]==0)
                    count[prime[j]]++;
        }

        ans=1;
        for(it=d.begin();it!=d.end();it++)
        {
            ans=(ans*(*it))%1000000007;
        }
        cout<<ans<<endl;
    }
    return 0;
}
