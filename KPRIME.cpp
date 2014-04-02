#include<iostream>
#include<stdio.h>
#include<cstring>
#include<math.h>
#define limit 100005

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

int main()
{
    int i,j,k,T,A,B,K;
    int count;
    int prime[10000],prime_size=0;
    int KPRIME[limit][5];
    generate_prime();

    sieve[2]=true;
    sieve[3]=true;

    for(i=0;i<limit;i++)
    {
        if(sieve[i])
            prime[prime_size++]=i;
        KPRIME[i][0]=i;
    }

    for(i=0;i<limit;i++)
    {
        count=1;
        KPRIME[i][1]=KPRIME[i-1][1];
        KPRIME[i][2]=KPRIME[i-1][2];
        KPRIME[i][3]=KPRIME[i-1][3];
        KPRIME[i][4]=KPRIME[i-1][4];

        for(j=0;j<prime_size && prime[j]<=i/2;j++)
        {
            if(i%prime[j]==0)
                count++;
            if(count==2)
                KPRIME[i][1]++;

            else if(count==3)
                KPRIME[i][2]++;

            else if(count==4)
                KPRIME[i][3]++;

            else if(count==5)
            {
                KPRIME[i][4]++;
                break;
            }
        }

    }

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d%d%d",&A,&B,&K);
        printf("%d\n",KPRIME[B][K-1]-KPRIME[A-1][K-1]);
    }

    return 0;
}
