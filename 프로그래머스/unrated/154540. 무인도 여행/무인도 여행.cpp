#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
bool visited[101][101];
int board[101][101];
vector<int> result;
int direction_x[4] = {0,0,1,-1};
int direction_y[4] = {1,-1,0,0};//right left down up
int backtracking(int start,int end,int value,vector<string> maps){
    queue<pair<int,int>> q;
    value+=board[start][end];
    visited[start][end]=true;
    for(int i=0;i<4;i++){
        int temp_start = start+direction_x[i];
        int temp_end = end+direction_y[i];
        if(temp_start>=maps.size()||temp_start<0||
           temp_end>=maps[0].length()||temp_end<0)continue;
        if(visited[temp_start][temp_end])continue;
        q.push({temp_start,temp_end});
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(visited[x][y]==true)continue;
        visited[x][y]=true;
        value+=board[x][y];
        for(int i=0;i<4;i++){
            int temp_start = x+direction_x[i];
            int temp_end = y+direction_y[i];
            if(temp_start>=maps.size()||temp_start<0||
               temp_end>=maps[0].length()||temp_end<0)continue;
            if(visited[temp_start][temp_end])continue;
            q.push({temp_start,temp_end});
        }   
    }
    return value;
}
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    fill(&visited[0][0],&visited[100][101],false);
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[i].length();j++){
            if(maps[i][j]=='X'){
                visited[i][j]=true;
                board[i][j]=-1;    
            }else{
                board[i][j]=(int)maps[i][j]-48;    
            }
        }
    }
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[i].length();j++){
            if(visited[i][j]==true)continue;
            int temp = backtracking(i,j,0,maps);
            result.push_back(temp);
        }
    }
    if(result.size()==0){
        result.push_back(-1);
    }
    sort(result.begin(),result.end());
    return result;
}