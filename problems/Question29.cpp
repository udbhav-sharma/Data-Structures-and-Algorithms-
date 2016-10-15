//
// Created by udbhav on 2/10/16.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

void calculateSubTreePenalty(vector<int> tree[], int node, vector<int> &penalty, vector<int> &subtreePenalty){
    subtreePenalty[node]=penalty.at(node);

    for(int i=0;i<tree[node].size();i++) {
        calculateSubTreePenalty(tree,tree[node][i],penalty,subtreePenalty);
        subtreePenalty[node] += subtreePenalty.at(tree[node][i]);
    }
}

int main() {
    int N,x;
    cin>>N;

    vector<int> tree[N+1];
    vector<int> penalty(N+1);
    vector<int> subtreePenalty(N+1);
    multimap<int,int> penaltyMap;
    multimap<int,int>::iterator it;
    int penaltySum=0;

    for(int i=1;i<=N;i++){
        cin>>x;
        penalty[i]=x;
        penaltySum+=x;
    }

    for(int i=2;i<=N;i++){
        cin>>x;
        tree[x].push_back(i);
    }

    calculateSubTreePenalty(tree,1, penalty, subtreePenalty);

    for(int i=1;i<subtreePenalty.size();i++) {
        cout<<i<<" - "<<subtreePenalty.at(i)<<endl;
    }

    cout<<"PenaltySum="<<penaltySum<<endl;
    int totalPenalty=0;
    penaltyMap.insert(pair<int,int>(penalty.at(1),1));
    while(penaltyMap.size()>0){
        it = penaltyMap.end();
        --it;
        int node=it->second;
        penaltyMap.erase(it);

        penaltySum -= penalty.at(node);
        totalPenalty += penaltySum;

        cout<<" node="<<node<<" PenaltySum="<<penaltySum<<" TotalPenalty="<<totalPenalty<<endl;
        for(int i=0;i<tree[node].size();i++) {
            cout<<subtreePenalty.at(tree[node].at(i))<<", "<<tree[node].at(i)<<endl;
            penaltyMap.insert(pair<int, int>(subtreePenalty.at(tree[node].at(i)), tree[node].at(i)));
        }
    }

    cout<<totalPenalty<<endl;
    return 0;
}