#include<iostream>
#include<algorithm>

using namespace std;

struct Item
{
    int weight,value;
    bool operator <(const Item& that) const
    {
        return this->weight<that.weight;
    }
};

int main()
{
    int i,j,N,Knapsack;
    cin>>N>>Knapsack;

    Item item[N+1];
    int Ans[N][Knapsack+1];

    item[0].value=0;
    item[0].weight=0;

    for(i=1;i<=N;i++)
    {
        cin>>item[i].value>>item[i].weight;
    }

    sort(item,item+N+1);

    for(i=0;i<=Knapsack;i++)
    {
        Ans[0][i]=0;
    }

    for(j=0;j<=N;j++)
        Ans[j][0]=0;

    for(i=1;i<=N;i++)
    {
        for(j=1;j<=Knapsack;j++)
        {
            if(j>=item[i].weight)
            {
                Ans[i][j]=max(Ans[i-1][j],(item[i].value+Ans[i][j-item[i].weight]));
            }
            else
                Ans[i][j]=Ans[i-1][j];
        }
    }

    cout<<Ans[N][Knapsack]<<endl;
    return 0;
}
