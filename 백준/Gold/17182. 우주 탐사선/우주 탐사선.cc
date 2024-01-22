#include <bits/stdc++.h>

using namespace std;
bool visited[10] = {0,};
vector<int> dis[10];int planet;int final_result=1000000000;
vector<tuple<int,int,int>> fly;
void dfs(int start,int value,int visit){
    if(visit==planet){
        final_result=min(final_result,value);
        return;
    }
    if(value>final_result)return;
    for(int i=0;i<dis[start].size();i++){
        if(visited[i])continue;
        visited[i]=true;
        dfs(i,value+dis[start][i],visit+1);
        visited[i]=false;
    }
}

int main(){
    int start;
    cin>>planet>>start;

    for(int i=0;i<planet;i++){
        for(int j=0;j<planet;j++){
            int temp;
            cin>>temp;
            dis[i].push_back(temp);
        }
    }
    for(int a=0;a<planet;a++) {
        for (int i = 0; i < planet; i++) {
            for (int j = 0; j < planet; j++) {
                if (i == j)continue;
                if (i == a || j == a)continue;
                dis[i][j] = min(dis[i][j], dis[i][a] + dis[a][j]);
            }
        }
    }
    visited[start]=true;
    dfs(start,0,1);
    cout << final_result;
}