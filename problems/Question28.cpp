//
// Created by udbhav on 2/10/16.
//

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    int N,K;
    long long p,d,result=0;
    cin>>N>>K;

    multiset<long long> diff;
    multiset<long long>::iterator it;
    for(int i=0;i<N;i++){
        cin>>p>>d;
        if(diff.size()<K){
            result += p;
            diff.insert(-p-d);
        }
        else{
            it = diff.end();
            --it;
            long long temp1 = result+p+(*it);
            long long temp2 = result-d;
            if(temp1>temp2) {
                diff.erase(it);
                result = temp1;
                diff.insert(-p-d);
            }
            else
                result = temp2;
        }
        //cout<<"i="<<i<<" result="<<result<<" size="<<diff.size()<<endl;
    }

    cout<<max(result,0LL)<<endl;
    return 0;
}