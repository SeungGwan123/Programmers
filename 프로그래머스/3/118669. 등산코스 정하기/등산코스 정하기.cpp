#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    vector<pair<int,int>> walk[n+1];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int s[50001]={0,};
    int height=0;
    int result = 50001;
    int min_summit=50001;
    bool visited[50001]={0,};
    for(int i=0;i<paths.size();i++){
        int start = paths[i][0];
        int end = paths[i][1];
        int value = paths[i][2];
        walk[start].push_back({value,end});
        walk[end].push_back({value,start});
        //sort(walk[start].begin(),walk[start].end());
        //sort(walk[end].begin(),walk[end].end());
    }
    for(int i=0;i<gates.size();i++){
        int gate = gates[i];
        visited[gate]=true;
        for(int j=0;j<walk[gate].size();j++){
            int value = walk[gate][j].first;
            int end = walk[gate][j].second;
            pq.push({value,end});
        }
    }
    for(int i=0;i<summits.size();i++){
        s[summits[i]]=1;
        min_summit = min(min_summit,summits[i]);
    }
    while(!pq.empty()){
        int value = pq.top().first;
        int end = pq.top().second;
        pq.pop();
        if(visited[end])continue;
        if(result<50001&&height<value)break;
        visited[end]=true;
        height = max(height,value);
        if(s[end]==1){
            result = min(result,end);
            if(summits.size()==1||end==min_summit)break;
            else continue;
        }else{
            for(int i=0;i<walk[end].size();i++){
                int t_value = walk[end][i].first;
                int t_end = walk[end][i].second;
                if(visited[t_end])continue;
                if(result<50001){
                    if(t_value<=height) pq.push({t_value,t_end});
                    else continue;
                }else{
                    pq.push({t_value,t_end});
                }
            }
        }
    }
    answer.push_back(result);
    answer.push_back(height);
    return answer;
}