//
// Created by udbhav on 1/10/16.
//

#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main(){
    int N, x;
    cin>>N;
    int n = 2*N-1;

    map<int,int> countMap, result;
    map<int,int>::iterator mapIt;
    vector<set<int>> heightRoots(n+1);

    for(int i=0;i<n;i++) {
        cin >> x;
        if(countMap.find(x)==countMap.end())
            countMap.insert(pair<int,int>(x,1));
        else
            countMap.find(x)->second++;
    }

    for(int i=0;i<heightRoots.size();i++) {
        set<int> roots;
        heightRoots.at(i) = roots;
    }

    int log=0;
    x = N;
    while(x>0){
        x >>= 1;
        log++;
    }

    heightRoots.at(log).insert(1);
    for(mapIt=countMap.begin(); mapIt!=countMap.end(); mapIt++) {
        int key = mapIt->first, value = mapIt->second;
        if(heightRoots.at(value).empty()){
            cout<<"NO"<<endl;
            return 0;
        }

        int wh = *(heightRoots.at(value).begin());
        heightRoots.at(value).erase(heightRoots.at(value).begin());
        result.insert(pair<int,int>(key,wh));
        for(int i=0;i<value-1;i++){
            heightRoots.at(value-i-1).insert(wh*2+1);
            wh<<=1;
        }
    }

    int segmentTree[n+1]={0};
    for(mapIt=result.begin(); mapIt!=result.end(); mapIt++) {
        int i = mapIt->second;
        while(i<=n){
            segmentTree[i] = mapIt->first;
            i<<=1;
        }
    }

    cout<<"YES"<<endl;
    for(int i=1;i<n;i++)
        cout<<segmentTree[i]<<" ";
    cout<<segmentTree[n]<<endl;

    return 0;
}