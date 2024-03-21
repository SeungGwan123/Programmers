#include <string>
#include <bits/stdc++.h>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
    pair<int,int> my = {0,0};
    set<tuple<int,int,int,int>> s;
    for(int i=0;i<dirs.length();i++){
        char temp = dirs[i];
        pair<int,int> now_dir;
        if(temp=='U') now_dir = {dir[0][0],dir[0][1]};
        else if(temp=='D') now_dir = {dir[1][0],dir[1][1]};
        else if(temp=='L') now_dir = {dir[2][0],dir[2][1]};
        else now_dir = {dir[3][0],dir[3][1]};
        int x = my.first+now_dir.first;
        int y = my.second+now_dir.second;
        if(x<-5||x>5||y<-5||y>5) continue;
        if(s.count({my.first,my.second,x,y})>0){
            my = {x,y};
        }else{
            s.insert({my.first,my.second,x,y});
            s.insert({x,y,my.first,my.second});
            my = {x,y};
            answer++;
        }
    }
    return answer;
}