#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n;int m;
int result=1000000000;
vector<pair<int,int>> home;
vector<pair<int,int>> chicken;
int visited[13];
//int v_home[100];
int check_v = 0;
void back(vector<pair<int, int>> h2c[],int start){
    //if(value>=result)return;
    int value=0;
    if(check_v==m){
        for(int i=0;i<home.size();i++){
            if(value>=result) return;
//            if(v_home[i]!=-1){
//                if(visited[v_home[i]]>=0)continue;
//            }
            for(int j=0;j<h2c[i].size();j++){
                if(visited[h2c[i][j].second]>=0) {
                    visited[h2c[i][j].second]+=h2c[i][j].first;
                    value+=h2c[i][j].first;
//                    v_home[i]=h2c[i][j].second;
                    break;
                }
            }
        }
        result = min(result,value);
        return ;
    }
    for(int i=start;i<chicken.size();i++){
        if(visited[i]==0)continue;
        visited[i]=0;
        check_v++;
        back(h2c,i);
        visited[i]=-1;
        check_v--;
    }
}
int main() {

     cin>>n>>m;
     vector<int> v[n];
     fill_n(visited, 13, -1);
//    fill_n(v_home, 100, -1);
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             int temp;
             cin>>temp;
             v[i].push_back(temp);
             if(temp==1) home.push_back({i, j});
             else if(temp==2) chicken.push_back({i, j});
         }
     }
     vector<pair<int, int>> h2c[home.size()];
     for(int i=0;i<home.size();i++){
         int a = home[i].first;
         int b = home[i].second;
         for(int j=0;j<chicken.size();j++){
             int x = chicken[j].first;
             int y = chicken[j].second;
             h2c[i].push_back({abs(a - x) + abs(b - y), j});
         }
         sort(h2c[i].begin(), h2c[i].end());
     }
     back(h2c,0);
     cout<<result;
}