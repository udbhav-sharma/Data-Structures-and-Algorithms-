#include<iostream>
using namespace std;
int a[300000000];
int t,n;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%2==0) cout<<"ALICE"<<endl;
        else cout<<"BOB"<<endl;
    }
    return 0;
}
