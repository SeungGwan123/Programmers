#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>board[101][101];
int s_x;
int s_y;
int l_x;
int l_y;
int e_x;
int e_y;
bool visited[101][101];
bool vvisited[101][101];
int dfs(int start_x,int start_y,int Laber_x,int Laber_y,int Exit_x,int Exit_y){
    queue<tuple<int,int,int>> q;
    int finish=0;
    bool check=false;
    visited[start_x][start_y]=true;
    for(int i=0;i<board[start_x][start_y].size();i++){
        int x;int y;
        tie(x,y)=board[start_x][start_y][i];
        q.push({x,y,1});
    }
    while(!q.empty()){
        int x;int y;int value;
        tie(x,y,value) = q.front();
        q.pop();
        if(x==Laber_x&&y==Laber_y){
            check=true;
            finish=value;
            break;
        }else{
            if(visited[x][y]==true)continue;
            visited[x][y]=true;
            for(int i=0;i<board[x][y].size();i++){
                int t_x;int t_y;int t_v;
                tie(t_x,t_y)=board[x][y][i];
                if(visited[t_x][t_y]==true)continue;
                q.push({t_x,t_y,value+1});
            }
        }
    }
    return finish;
}
int ddfs(int start_x,int start_y,int Laber_x,int Laber_y,int Exit_x,int Exit_y){
    queue<tuple<int,int,int>> q;
    int finish=0;
    bool check=false;
    visited[start_x][start_y]=true;
    for(int i=0;i<board[start_x][start_y].size();i++){
        int x;int y;
        tie(x,y)=board[start_x][start_y][i];
        q.push({x,y,1});
    }
    while(!q.empty()){
        int x;int y;int value;
        tie(x,y,value) = q.front();
        q.pop();
        if(x==Exit_x&&y==Exit_y){
            check=true;
            finish=value;
            break;
        }else{
            if(visited[x][y]==true)continue;
            visited[x][y]=true;
            for(int i=0;i<board[x][y].size();i++){
                int t_x;int t_y;
                tie(t_x,t_y)=board[x][y][i];
                if(visited[t_x][t_y]==true)continue;
                q.push({t_x,t_y,value+1});
            }
        }
    }
    return finish;
}
int solution(vector<string> maps) {
    int answer = 0;
    //길=0 벽=-1 시작 =1 래버=2 도착=3
    fill(&visited[0][0],&visited[100][101],false);
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[i].length();j++){
            char temp = maps[i][j];
            int tp = 0;
            if(temp=='X')continue;
            if(temp=='O')tp=0;
            else if(temp=='S'){
                tp=1;
                s_x=i;
                s_y=j;
            }
            else if(temp=='L'){
                tp=2;
                l_x=i;
                l_y=j;
            }
            else {
                tp=3;
                e_x=i;
                e_y=j;
            }
            if(i!=0){//위
                char tt = maps[i-1][j];
                if(tt!='X'){
                    board[i][j].push_back({i-1,j});
                }
            }
            if(j!=0){//좌
                char tt = maps[i][j-1];
                if(tt!='X'){
                    board[i][j].push_back({i,j-1});
                }
            }
            if(i!=maps.size()-1){//아래
                char tt = maps[i+1][j];
                if(tt!='X'){
                    board[i][j].push_back({i+1,j});
                }
            }
            if(j!=maps[i].length()-1){//오
                char tt = maps[i][j+1];
                if(tt!='X'){
                    board[i][j].push_back({i,j+1});
                }
            }
        }
    }
        int middle = dfs(s_x,s_y,l_x,l_y,e_x,e_y);
        if(middle!=0){
            fill(&visited[0][0],&visited[100][101],false);
            int end = ddfs(l_x,l_y,s_x,s_y,e_x,e_y);
            if(end!=0){
                answer=middle+end;
            }else{
                answer=-1;
            }
        }else{
            answer=-1;
        }
    return answer;
}