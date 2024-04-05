#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int parents[101];
int n;
void init(){
    for(int i=0;i<n;i++){
        parents[i]=i;
    }
}
int Find(int x){
    if(parents[x]==x) return x;
    return parents[x] = Find(parents[x]);
}
void Union(int x,int y){
    x = Find(x);
    y = Find(y);
    if(x!=y){
        if(x<y) parents[y]=x;
        else parents[x]=y;
    }
}
int main() {
    cin>>n;
    double result = 0;
    int check =0;
    vector<pair<double,double>> v;
    priority_queue<tuple<double,int,int>,vector<tuple<double,int,int>>,greater<tuple<double,int,int>>> pq;
    bool visited[n+1];
    fill_n(visited, n + 1, false);
    for(int i=0;i<n;i++){
        double a;double b;
        cin>>a>>b;
        v.push_back({a, b});
    }
    for(int i=0;i<n;i++){
        double a = v[i].first;
        double b = v[i].second;
        for(int j=i+1;j<n;j++){
            double x = v[j].first;
            double y = v[j].second;
            double route = sqrt(pow(a-x,2)+pow(b-y,2));
            pq.push({route,i,j});
        }
    }
    init();
    while(!pq.empty()){
        double value;int start;int end;
        tie(value, start, end) = pq.top();
        pq.pop();
        if(Find(start)==Find(end))continue;
        Union(start, end);
        result+=value;
    }
    cout<<fixed;
    cout.precision(2);
    cout<<result;
}
