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
            //if(i==start) fly.push_back({temp,start,j});
        }
    }
    for(int a=0;a<planet;a++) {
        for (int i = 0; i < planet; i++) {
            for (int j = 0; j < planet; j++) {
                if (i == j)continue;
                if (i == a || j == a)continue;
                dis[i][j] = min(dis[i][j], dis[i][a] + dis[a][j]);
                //if(i==start) get<0>(fly[j])=dis[i][j];
            }
        }
    }
    visited[start]=true;
    dfs(start,0,1);
//    for(int j=0;j<dis[start].size();j++) {
//        if(start==j)continue;
//        int visit = 1;
//        int result = 0;
//        visited[start] = true;
//        fly.push_back({dis[start][j],start,j});
//        //sort(fly.begin(), fly.end());
//        int last_end = start;
//        while (visit < planet) {
//            int value;
//            int start;
//            int end;
//            tie(value, start, end) = fly[0];
//            fly.erase(fly.begin(), fly.begin() + 1);
//            if (visited[end])continue;
//            for (int i = 0; i < fly.size(); i++) {
//                int v;
//                int s;
//                int e;
//                tie(v, s, e) = fly[i];
//                fly[i] = {v - dis[last_end][s], s, e};
//                fly[i] = {v + dis[end][s], s, e};
//            }
//            visited[end] = true;
//            result += value;
//            visit++;
//            last_end = end;
//            for (int i = 0; i < dis[end].size(); i++) {
//                if (visited[i])continue;
//                fly.push_back({dis[end][i], end, i});
//            }
//            sort(fly.begin(), fly.end());
//        }
//        final_result = min(final_result, result);
//    }
    cout << final_result;
}