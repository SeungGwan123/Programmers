#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

pair<int,int> direction[4] = {{0,1},{-1,0},{1,0},{0,-1}};
int answer = 0;
int result = 100000;
void bbfs(pair<int,int> r_start,pair<int,int> b_start,vector<int> red_visit[],vector<int> blue_visit[],pair<int,int> r_end,pair<int,int> b_end,int height,int width,int time){
        bool check = false;
        pair<int,int> red = r_start;
        int red_x = red.first;
        int red_y = red.second;
        pair<int,int> blue = b_start;
        int blue_x = blue.first;
        int blue_y = blue.second;
        if(time>=result)return;
        if(red==r_end&&blue==b_end&&(time<result)){
            result = min(time,result);
            answer = result;
            return;
        }
        for(int i=0;i<4;i++){
            int x = direction[i].first;
            int y = direction[i].second;
            int x_red = red_x; int y_red = red_y;
            if(red!=r_end){
                x_red = red_x+x;
                y_red = red_y+y;
            }
            if(x_red>=height||x_red<0||y_red>=width||y_red<0)continue;
            if(red_visit[x_red][y_red]==1&&red!=r_end)continue;
            if(x_red==blue_x&&y_red==blue_y)continue;
            for(int j=0;j<4;j++){
                int x = direction[j].first;
                int y = direction[j].second;
                int x_blue = blue_x; int y_blue = blue_y;
                if(blue!=b_end){
                    x_blue = blue_x+x;
                    y_blue = blue_y+y;
                }
                if(x_blue>=height||x_blue<0||y_blue>=width||y_blue<0)continue;
                if(blue_visit[x_blue][y_blue]==1&&blue!=b_end)continue;
                if((red_x==x_red&&red_y==y_red)&&(blue_x==x_blue&&blue_y==y_blue))continue;
                if(x_red==x_blue&&y_red==y_blue)continue;
                red_visit[x_red][y_red]=1;
                blue_visit[x_blue][y_blue]=1;
                bbfs({x_red,y_red},{x_blue,y_blue},red_visit,blue_visit,r_end,b_end,height,width,time+1);
                red_visit[x_red][y_red]=0;
                blue_visit[x_blue][y_blue]=0;
            }
        }
}
void bfs(pair<int,int> r_start,pair<int,int> b_start,vector<int> red_visit[],vector<int> blue_visit[],pair<int,int> r_end,pair<int,int> b_end,int height,int width,int time){
    bool check = false;
    pair<int,int> red = r_start;
    int red_x = red.first;
    int red_y = red.second;
    pair<int,int> blue = b_start;
    int blue_x = blue.first;
    int blue_y = blue.second;
    if(time>=result)return;
    if(red==r_end&&blue==b_end&&(time<result)){
        result = min(time,result);
        answer = result;
        return;
    }
    for(int i=0;i<4;i++){
        int x = direction[i].first;
        int y = direction[i].second;
        int x_blue = blue_x; int y_blue = blue_y;
        if(blue!=b_end){
            x_blue = blue_x+x;
            y_blue = blue_y+y;
        }
        if(x_blue>=height||x_blue<0||y_blue>=width||y_blue<0)continue;
        if(blue_visit[x_blue][y_blue]==1&&blue!=b_end)continue;
        if(x_blue==red_x&&y_blue==red_y)continue;
        for(int j=0;j<4;j++){
            int x = direction[j].first;
            int y = direction[j].second;
            int x_red = red_x; int y_red = red_y;
            if(red!=r_end){
                x_red = red_x+x;
                y_red = red_y+y;
            }
            if(x_red>=height||x_red<0||y_red>=width||y_red<0)continue;
            if(red_visit[x_red][y_red]==1&&red!=r_end)continue;
            if((blue_x==x_blue&&blue_y==y_blue)&&(red_x==x_red&&red_y==y_red))continue;
            if(x_blue==x_red&&y_blue==y_red)continue;
            red_visit[x_red][y_red]=1;
            blue_visit[x_blue][y_blue]=1;
            bfs({x_red,y_red},{x_blue,y_blue},red_visit,blue_visit,r_end,b_end,height,width,time+1);
            red_visit[x_red][y_red]=0;
            blue_visit[x_blue][y_blue]=0;
        }
    }
}
int solution(vector<vector<int>> maze) {

    vector<int> red_visit[maze.size()];
    vector<int> blue_visit[maze.size()];

    pair<int,int> r_start; pair<int,int> r_end; pair<int,int> b_start; pair<int,int> b_end;
    int height = maze.size();
    int width = maze[0].size();
    for(int i=0;i<maze.size();i++){
        for(int j=0;j<maze[i].size();j++){
            red_visit[i].push_back(0);
            blue_visit[i].push_back(0);
            if(maze[i][j]==1) r_start = {i,j};
            if(maze[i][j]==2) b_start = {i,j};
            if(maze[i][j]==3) r_end = {i,j};
            if(maze[i][j]==4) b_end = {i,j};
            if(maze[i][j]==5){
                red_visit[i][j]=1;
                blue_visit[i][j]=1;
            }
        }
    }
    queue<tuple<pair<int,int>,pair<int,int>,int>> q;
    q.push({r_start,b_start,0});
    red_visit[r_start.first][r_start.second]=1;
    blue_visit[b_start.first][b_start.second]=1;
    bbfs(r_start,b_start,red_visit,blue_visit,r_end,b_end,height,width,0);
    bfs(r_start,b_start,red_visit,blue_visit,r_end,b_end,height,width,0);
    return answer;
}
