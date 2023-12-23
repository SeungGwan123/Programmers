#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> land) {
    int answer = 0;
    vector<int> visit[land.size()];
    vector<int> oil[land.size()];
    queue<pair<int,int>> q;
    int number =0;
    vector<int> oil_size;
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    for(int i=0;i<land.size();i++){
        for(int j=0;j<land[i].size();j++){
            visit[i].push_back(0);
            oil[i].push_back(-1);
        }
    }
    for(int i=0;i<land.size();i++){
        for(int j=0;j<land[i].size();j++){
            if(land[i][j]==1&&visit[i][j]==0){
                q.push({i,j});
                visit[i][j]=1;
                int total=1;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    //visit[i][j]=1;
                    oil[x][y]=number;
                    q.pop();
                    for(int d=0; d < 4; d++){
                        int a = x+dir[d][0];
                        int b = y+dir[d][1];
                        if(a<0||a>=land.size()||b<0||b>=land[d].size())continue;
                        if(visit[a][b]==1||land[a][b]==0)continue;
                        q.push({a,b});
                        visit[a][b]=1;
                        total++;
                    }
                }
                oil_size.push_back(total);
                number++;
            }
        }
    }
    for(int j=0;j<land[0].size();j++){
        set<int> s;
        int temp_size=0;
        for(int i=0;i<land.size();i++){
            if(oil[i][j]>-1){
                if(s.count(oil[i][j])==0){
                    s.insert(oil[i][j]);
                    temp_size+=oil_size[oil[i][j]];
                }
            }
        }
        answer = max(answer,temp_size);
    }
    return answer;
}