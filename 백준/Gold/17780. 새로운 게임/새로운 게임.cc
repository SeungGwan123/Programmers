#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>> horse;
vector<int> board[14];
int b_size;int horse_size;
vector<pair<pair<int,int>,pair<int,int>>> location[14];
int turn=0;
int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
vector<int> bh[14]; bool check=false;
void blue(int x,int y,int b_num,int b_dir,int t_num,int t_dir,int move_x,int move_y) {
    switch (b_dir) {
        case 1:
            b_dir = 2;
            break;
        case 2:
            b_dir = 1;
            break;
        case 3:
            b_dir = 4;
            break;
        case 4:
            b_dir = 3;
            break;
    }
    move_x = x+dir[b_dir-1][0];
    move_y = y+dir[b_dir-1][1];
    if (move_x < 0 || move_x >= b_size || move_y < 0 || move_y >= b_size) {
        location[x][y].first.second = b_dir;
    }else if(board[move_x][move_y] == 2){
        location[x][y].first.second = b_dir;
    }else{
        int new_b_num = location[move_x][move_y].first.first;
        int new_b_dir = location[move_x][move_y].first.second;
        int new_t_num = location[move_x][move_y].second.first;
        int new_t_dir = location[move_x][move_y].second.second;
        location[x][y]={{-1,-1},{-1,-1}};
        if(board[move_x][move_y]==0){
            if(new_b_num==-1){
                location[move_x][move_y].first.first = b_num;
                location[move_x][move_y].first.second = b_dir;
                horse[b_num]={move_x,move_y};
                if(t_num!=-1) {
                    location[move_x][move_y].second.first = t_num;
                    location[move_x][move_y].second.second = t_dir;
                    horse[t_num] = {move_x, move_y};
                }
                bh[move_x][move_y]+=bh[x][y];
                bh[x][y]=0;
                if(bh[move_x][move_y]>=4)check=true;
            }else{
                if(new_t_num==-1) {
                    if (t_num == -1) {
                        location[move_x][move_y].second.first = b_num;
                        location[move_x][move_y].second.second = b_dir;
                        horse[b_num]={move_x,move_y};
                        bh[move_x][move_y]+=bh[x][y];
                        bh[x][y]=0;
                        if(bh[move_x][move_y]>=4)check=true;
                    } else {
                        horse[b_num] = {-1, -1};
                        horse_size--;
                        location[move_x][move_y].second.first = t_num;
                        location[move_x][move_y].second.second = t_dir;
                        horse[t_num]={move_x,move_y};
                        bh[move_x][move_y]+=bh[x][y];
                        bh[x][y]=0;
                        if(bh[move_x][move_y]>=4)check=true;
                    }
                }else{
                    horse[new_t_num] = {-1, -1};
                    horse_size--;
                    if (t_num == -1) {
                        location[move_x][move_y].second.first = b_num;
                        location[move_x][move_y].second.second = b_dir;
                        horse[b_num]={move_x,move_y};
                        bh[move_x][move_y]+=bh[x][y];
                        bh[x][y]=0;
                        if(bh[move_x][move_y]>=4)check=true;
                    } else {
                        horse[b_num] = {-1, -1};
                        horse_size--;
                        location[move_x][move_y].second.first = t_num;
                        location[move_x][move_y].second.second = t_dir;
                        horse[t_num]={move_x,move_y};
                        bh[move_x][move_y]+=bh[x][y];
                        bh[x][y]=0;
                        if(bh[move_x][move_y]>=4)check=true;
                    }
                }
            }
        }else if(board[move_x][move_y]==1){
            if(new_b_num==-1){
                if(t_num==-1){
                    location[move_x][move_y].first.first = b_num;
                    location[move_x][move_y].first.second = b_dir;
                    horse[b_num] = {move_x, move_y};
                    bh[move_x][move_y] += bh[x][y];
                    bh[x][y] = 0;
                    if (bh[move_x][move_y] >= 4)check = true;
                }else {
                    if(t_num!=-1) {
                        location[move_x][move_y].first.first = t_num;
                        location[move_x][move_y].first.second = t_dir;
                        horse[t_num] = {move_x, move_y};
                    }
                    location[move_x][move_y].second.first = b_num;
                    location[move_x][move_y].second.second = b_dir;
                    horse[b_num] = {move_x, move_y};
                    
                    bh[move_x][move_y] += bh[x][y];
                    bh[x][y] = 0;
                    if (bh[move_x][move_y] >= 4)check = true;
                }
            }else{
                if(new_t_num==-1) {
                    if (t_num == -1) {
                        location[move_x][move_y].second.first = b_num;
                        location[move_x][move_y].second.second = b_dir;
                        horse[b_num]={move_x,move_y};
                        bh[move_x][move_y]+=bh[x][y];
                        bh[x][y]=0;
                        if(bh[move_x][move_y]>=4)check=true;
                    } else {
                        horse[t_num] = {-1, -1};
                        horse_size--;
                        location[move_x][move_y].second.first = b_num;
                        location[move_x][move_y].second.second = b_dir;
                        horse[b_num]={move_x,move_y};
                        bh[move_x][move_y]+=bh[x][y];
                        bh[x][y]=0;
                        if(bh[move_x][move_y]>=4)check=true;
                    }
                }else{
                    horse[new_t_num] = {-1, -1};
                    horse_size--;
                    if (t_num == -1) {
                        location[move_x][move_y].second.first = b_num;
                        location[move_x][move_y].second.second = b_dir;
                        horse[b_num]={move_x,move_y};
                        bh[move_x][move_y]+=bh[x][y];
                        bh[x][y]=0;
                        if(bh[move_x][move_y]>=4)check=true;
                    } else {
                        horse[t_num] = {-1, -1};
                        horse_size--;
                        location[move_x][move_y].second.first = b_num;
                        location[move_x][move_y].second.second = b_dir;
                        horse[b_num]={move_x,move_y};
                        bh[move_x][move_y]+=bh[x][y];
                        bh[x][y]=0;
                        if(bh[move_x][move_y]>=4)check=true;
                    }
                }
            }
        }
    }
}

// 1 2 3 4 오 왼 위 아래
int main(){

    cin>>b_size>>horse_size;
    for(int i=0;i<b_size;i++){
        for(int j=0;j<b_size;j++){
            int temp;
            cin>> temp;
            board[i].push_back(temp);
            location[i].push_back({{-1,-1},{-1,-1}});
            bh[i].push_back(0);
        }
    }
    for(int i=0;i<horse_size;i++){
        int x;int y;int z;
        cin>>x>>y>>z;
        location[x-1][y-1]={{i,z},{-1,-1}};
        horse.emplace_back(x-1,y-1);
        bh[x-1][y-1]=1;
    }
    while(turn<=1000){
        if(check)break;
        turn++;
        //0 white 1 red 2 blue
        for(int i=0;i<horse.size();i++){
            if(check)break;
            int x = horse[i].first;
            int y = horse[i].second;
            if(x==-1&&y==-1)continue;
            int b_num = location[x][y].first.first;
            int b_dir = location[x][y].first.second;
            int t_num = location[x][y].second.first;
            int t_dir = location[x][y].second.second;
            if(b_num!=i||b_dir==-1)continue;
            int move_x = x+dir[b_dir-1][0];
            int move_y = y+dir[b_dir-1][1];
            if (move_x < 0 || move_x >= b_size || move_y < 0 || move_y >= b_size){
                blue(x, y, b_num, b_dir, t_num, t_dir, move_x, move_y);
            }else if(board[move_x][move_y] == 2) {
                blue(x, y, b_num, b_dir, t_num, t_dir, move_x, move_y);
            }
            else{
                int new_b_num = location[move_x][move_y].first.first;
                int new_b_dir = location[move_x][move_y].first.second;
                int new_t_num = location[move_x][move_y].second.first;
                int new_t_dir = location[move_x][move_y].second.second;
                location[x][y]={{-1,-1},{-1,-1}};
                if(board[move_x][move_y]==0){
                    if(new_b_num==-1){
                        location[move_x][move_y].first.first = b_num;
                        location[move_x][move_y].first.second = b_dir;
                        horse[b_num]={move_x,move_y};
                        if(t_num!=-1) {
                            location[move_x][move_y].second.first = t_num;
                            location[move_x][move_y].second.second = t_dir;
                            horse[t_num] = {move_x, move_y};
                        }
                        bh[move_x][move_y]+=bh[x][y];
                        bh[x][y]=0;
                        if(bh[move_x][move_y]>=4)check=true;
                    }else{
                        if(new_t_num==-1) {
                            if (t_num == -1) {
                                location[move_x][move_y].second.first = b_num;
                                location[move_x][move_y].second.second = b_dir;
                                horse[b_num]={move_x,move_y};
                                bh[move_x][move_y]+=bh[x][y];
                                bh[x][y]=0;
                                if(bh[move_x][move_y]>=4)check=true;
                            } else {
                                horse[b_num] = {-1, -1};
                                horse_size--;
                                location[move_x][move_y].second.first = t_num;
                                location[move_x][move_y].second.second = t_dir;
                                horse[t_num]={move_x,move_y};
                                bh[move_x][move_y]+=bh[x][y];
                                bh[x][y]=0;
                                if(bh[move_x][move_y]>=4)check=true;
                            }
                        }else{
                            horse[new_t_num] = {-1, -1};
                            horse_size--;
                            if (t_num == -1) {
                                location[move_x][move_y].second.first = b_num;
                                location[move_x][move_y].second.second = b_dir;
                                horse[b_num]={move_x,move_y};
                                bh[move_x][move_y]+=bh[x][y];
                                bh[x][y]=0;
                                if(bh[move_x][move_y]>=4)check=true;
                            } else {
                                horse[b_num] = {-1, -1};
                                horse_size--;
                                location[move_x][move_y].second.first = t_num;
                                location[move_x][move_y].second.second = t_dir;
                                horse[t_num]={move_x,move_y};
                                bh[move_x][move_y]+=bh[x][y];
                                bh[x][y]=0;
                                if(bh[move_x][move_y]>=4)check=true;
                            }
                        }
                    }
                }else if(board[move_x][move_y]==1){
                    if(new_b_num==-1){
                        if(t_num==-1){
                            location[move_x][move_y].first.first = b_num;
                            location[move_x][move_y].first.second = b_dir;
                            horse[b_num] = {move_x, move_y};
                            bh[move_x][move_y] += bh[x][y];
                            bh[x][y] = 0;
                            if (bh[move_x][move_y] >= 4)check = true;
                        }else {
                            if (t_num != -1) {
                                location[move_x][move_y].first.first = t_num;
                                location[move_x][move_y].first.second = t_dir;
                                horse[t_num] = {move_x, move_y};
                            }
                            location[move_x][move_y].second.first = b_num;
                            location[move_x][move_y].second.second = b_dir;
                            horse[b_num] = {move_x, move_y};
                            
                            bh[move_x][move_y] += bh[x][y];
                            bh[x][y] = 0;
                            if (bh[move_x][move_y] >= 4)check = true;
                        }
                    }else{
                        if(new_t_num==-1) {
                            if (t_num == -1) {
                                location[move_x][move_y].second.first = b_num;
                                location[move_x][move_y].second.second = b_dir;
                                horse[b_num]={move_x,move_y};
                                bh[move_x][move_y]+=bh[x][y];
                                bh[x][y]=0;
                                if(bh[move_x][move_y]>=4)check=true;
                            } else {
                                horse[t_num] = {-1, -1};
                                horse_size--;
                                location[move_x][move_y].second.first = b_num;
                                location[move_x][move_y].second.second = b_dir;
                                horse[b_num]={move_x,move_y};
                                bh[move_x][move_y]+=bh[x][y];
                                bh[x][y]=0;
                                if(bh[move_x][move_y]>=4)check=true;
                            }
                        }else{
                            horse[new_t_num] = {-1, -1};
                            horse_size--;
                            if (t_num == -1) {
                                location[move_x][move_y].second.first = b_num;
                                location[move_x][move_y].second.second = b_dir;
                                horse[b_num]={move_x,move_y};
                                bh[move_x][move_y]+=bh[x][y];
                                bh[x][y]=0;
                                if(bh[move_x][move_y]>=4)check=true;
                            } else {
                                horse[t_num] = {-1, -1};
                                horse_size--;
                                location[move_x][move_y].second.first = b_num;
                                location[move_x][move_y].second.second = b_dir;
                                horse[b_num]={move_x,move_y};
                                bh[move_x][move_y]+=bh[x][y];
                                bh[x][y]=0;
                                if(bh[move_x][move_y]>=4)check=true;
                            }
                        }
                    }
                }
            }
        }
    }
    if(turn>1000)cout<<"-1";
    else cout<<turn;
}

