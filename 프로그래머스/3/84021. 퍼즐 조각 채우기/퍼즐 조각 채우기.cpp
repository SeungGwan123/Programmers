#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    int width = table[0].size()-1;
    int height = table.size()-1;
    int g_width = game_board[0].size()-1;
    int g_height = game_board.size()-1;
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

    vector<int> block_size;
    vector<vector<pair<int,int>>> block_loc;
    vector<bool> block_check;
    int visited[table.size()][table[0].size()];
    int g_visited[game_board.size()][game_board[0].size()];
    fill_n(&visited[0][0],table.size()*table[0].size(),false);
    for(int i=0;i<table.size();i++){
        for(int j=0;j<table[i].size();j++){
            if(visited[i][j])continue;
            if(table[i][j]==0){
                table[i][j]=-1;
                visited[i][j]=true;
                continue;
            }
            vector<pair<int,int>> temp;
            temp.push_back({i,j});
            pair<int,int> min_y_max_x = {i,j};
            pair<int,int> max_x_max_y = {i,j};
            pair<int,int> max_y_min_x = {i,j};
            block_check.push_back(false);
            int num = block_size.size();
            queue<pair<int,int>> q;
            q.push({i,j});
            int count = 0;
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(visited[x][y])continue;
                visited[x][y]=true;
                table[x][y]=num;
                count++;
                if(y<min_y_max_x.second) min_y_max_x = {x,y};
                else if(y==min_y_max_x.second&&x>min_y_max_x.first) min_y_max_x = {x,y};
                if(x>max_x_max_y.first) max_x_max_y = {x,y};
                else if(x==max_x_max_y.first&&y>max_x_max_y.second) max_x_max_y = {x,y};
                if(y>max_y_min_x.second) max_y_min_x = {x,y};
                else if(y==max_y_min_x.second&&x<max_y_min_x.first) max_y_min_x = {x,y};
                for(int d=0;d<4;d++){
                    int a = x+dir[d][0];
                    int b = y+dir[d][1];
                    if(a<0||a>height||b<0||b>width) continue;
                    if(visited[a][b]||table[a][b]==0)continue;
                    q.push({a,b});
                }
            }
            block_size.push_back(count);

            temp.push_back({min_y_max_x.second,width-min_y_max_x.first});
            temp.push_back({width-max_x_max_y.first,height-max_x_max_y.second});
            temp.push_back({height-max_y_min_x.second,max_y_min_x.first});
            block_loc.push_back(temp);
        }
    }

    vector<vector<int>> t_table = table;
    vector<vector<vector<int>>> total_table;
    total_table.push_back(t_table);
    for(int d=0;d<3;d++){
        for(int i=0; i<table.size(); i++){
            for(int j=0; j<table.size(); j++){
                t_table[i][j] = total_table[d][table.size() - j -1][i];
            }
        }
        total_table.push_back(t_table);
    }
    fill_n(&g_visited[0][0],game_board.size()*game_board[0].size(),false);
    vector<int> board_size;
    vector<pair<int,int>> board_loc;
    vector<bool> board_check;
    for(int i=0;i<game_board.size();i++){
        for(int j=0;j<game_board[i].size();j++){
            if(game_board[i][j]==1||g_visited[i][j])continue;
            board_check.push_back(false);
            board_loc.push_back({i,j});
            int count=0;
            queue<pair<int,int>> q;
            q.push({i,j});
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(g_visited[x][y])continue;
                g_visited[x][y]=true;
                count++;
                for(int d=0;d<4;d++){
                    int a = x+dir[d][0];
                    int b = y+dir[d][1];
                    if(a<0||a>g_height||b<0||b>g_width) continue;
                    if(g_visited[a][b]||game_board[a][b]==1)continue;
                    q.push({a,b});
                }
            }
            board_size.push_back(count);
        }
    }
    for(int i=0;i<board_size.size();i++){
        int now_size = board_size[i];
        for(int j=0;j<block_size.size();j++){
            if(now_size!=block_size[j]||block_check[j])continue;
            int now = block_size[j];
            int answer_check = false;
            for(int d=0;d<4;d++){
                int b_x = board_loc[i].first;
                int b_y = board_loc[i].second;
                int t_x = block_loc[j][d].first;
                int t_y = block_loc[j][d].second;
                int bo_x = t_x-b_x;
                int bo_y = t_y-b_y;
                bool same_check = false;
                queue<pair<int,int>> q;
                q.push({b_x,b_y});
                fill_n(&g_visited[0][0],game_board.size()*game_board[0].size(),false);
                while(!q.empty()){
                    int a = q.front().first;
                    int b = q.front().second;
                    q.pop();
                    if(g_visited[a][b])continue;
                    g_visited[a][b]=true;
                    for(int dd=0;dd<4;dd++){
                        int aa = a+dir[dd][0];
                        int bb = b+dir[dd][1];
                        if(aa<0||aa>g_height||bb<0||bb>g_width) continue;
                        if(g_visited[aa][bb]||game_board[aa][bb]==1)continue;
                        if(aa+bo_x<0||aa+bo_x>height||bb+bo_y<0||bb+bo_y>width){
                            same_check = true;
                            break;
                        }
                        if(total_table[d][aa+bo_x][bb+bo_y]!=j){
                            same_check = true;
                            break;
                        }else q.push({aa,bb});
                    }
                    if(same_check)break;
                }
                if(!same_check){
                    answer += now;
                    block_check[j]=true;
                    answer_check=true;
                    break;
                }
            }
            if(answer_check)break;
        }
    }
    return answer;
}