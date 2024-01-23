#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;int l;
    cin>>n>>l;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> v;
    set<int> s;
    map<int,int> m;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        pq.push({temp,i});
        if(i>=l){
            while(pq.top().second<=i-l)pq.pop();
        }
        cout<<pq.top().first<<" ";
    }
}