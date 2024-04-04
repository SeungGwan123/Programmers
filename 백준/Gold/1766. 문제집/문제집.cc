#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;int m;
    cin>>n>>m;
    map<int,int> v;
    vector<int> edge[n+1];
    vector<int> result;
    for(int i=1;i<=n;i++){
        v[i]=0;
    }
    for(int i=0;i<m;i++){
        int a;int b;
        cin>>a>>b;
        edge[a].push_back(b);
        v[b]++;
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto vi=v.begin();vi!=v.end();){
        if (vi->second == 0) {
            pq.push(vi->first);
            vi = v.erase(vi);
        }else vi++;
    }
    while(!pq.empty()){
        int now = pq.top();
        result.push_back(now);
        pq.pop();
        for(int i=0;i<edge[now].size();i++){
            v[edge[now][i]]--;
            if(v[edge[now][i]]==0){
                pq.push(edge[now][i]);
            }
        }
//        for(auto vi=v.begin();vi!=v.end();){
//            if (vi->second == 0) {
//                pq.push(vi->first);
//                vi = v.erase(vi);
//            }else vi++;
//        }
    }

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}
