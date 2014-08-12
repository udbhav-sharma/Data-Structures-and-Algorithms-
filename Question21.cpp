/*https://www.hackerrank.com/challenges/journey-to-the-moon*/

#include <vector>
#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;

#define maxn 100005

bool visited[maxn];
vector< vector<int> > pairs(maxn);

void DFS( int i,int& count)
{
    visited[i]=true;
    for(int j=0;j<pairs[i].size();j++)
        if(!visited[pairs[i][j]])
            DFS(pairs[i][j],++count);
}

int main()
{
    int N, I;
    scanf("%d%d",&N,&I);
    vector<int> country;
    for (int i = 0; i < I; ++i) {
        int a, b;
        scanf("%d%d",&a,&b);
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }

    long long result = 0;
    /** Write code to compute the result using N,I,pairs **/

    memset(visited,0,sizeof(visited));

    int count=0;

    for(int i=0;i<N;i++)
        if(!visited[i])
        {
            count=1;
            DFS(i,count);
            country.push_back(count);
            //cout<<count<<endl;
        }

    long long sum=0;
    for(int i=0;i<country.size();i++)
        sum+=country[i];

    for(int i=0;i<country.size();i++)
    {
        sum-=country[i];
        result+=sum*country[i];
    }

    cout << result << endl;
    return 0;
}
