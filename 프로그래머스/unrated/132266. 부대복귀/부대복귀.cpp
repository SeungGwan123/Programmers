#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int dfs(int start,int end,vector<int> map[],bool visited[]){
    queue<pair<int,int>> q;
    visited[start]=true;
    int result=0;
    for(int i=0;i<map[start].size();i++){
        q.push({map[start][i],1});
    }
    while(!q.empty()){
        int now = q.front().first;
        int value = q.front().second;
        q.pop();
        if(visited[now]==true)continue;
        if(now==end){
            result=value;
            break;
        }
        visited[now]=true;
        for(int i=0;i<map[now].size();i++){
            if(visited[map[now][i]]==true)continue;
            q.push({map[now][i],value+1});
        }
    }
    return result;
}
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<int> map[n+1];
    bool visited[n+1];
    for(int i=0;i<roads.size();i++){
        int start = roads[i][0];
        int end = roads[i][1];
        map[start].push_back(end);
        map[end].push_back(start);
    }
    for(int i=0;i<sources.size();i++){
        fill(visited,visited+n+1,false);
        int result = -1;
        if(sources[i]!=destination){
            result= dfs(sources[i],destination,map,visited);
        }
        if(result==0){
            answer.push_back(-1);
        }else if(result==-1){
            answer.push_back(0);
        }else{
            answer.push_back(result);
        }
    }
    return answer;
}