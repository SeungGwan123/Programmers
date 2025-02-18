#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int block=0;
//    set<pair<int,int>> block;
//    set<pair<int,int>> block_set;
    //0 X 1 Student 2 Teacher
    vector<int> board[n];
    vector<pair<int,int>> teacher;
    vector<pair<int,int>> student;
    vector<pair<pair<int,int>,pair<int,int>>> watch;
    set<pair<pair<int,int>,pair<int,int>>> twin;

    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char temp;
            cin>>temp;
            if(temp=='X')board[i].push_back(0);
            else if(temp=='S'){
                board[i].push_back(1);
                student.push_back({i, j});
            }
            else {
                board[i].push_back(2);
                teacher.push_back({i, j});
            }
        }
    }
    for(int i=0;i<teacher.size();i++){
        int t_x = teacher[i].first;
        int t_y = teacher[i].second;
        for(int j=0;j<4;j++){
            bool check=false;
            int move_x = t_x+dir[j][0];
            int move_y = t_y+dir[j][1];
            int move_a = move_x;
            int move_b = move_y;
            if(move_x<0||move_x>=n||move_y<0||move_y>=n) continue;
            else {
                if(board[move_x][move_y]==1){
                    cout<<"NO";
                    return 0;
                }else if(board[move_x][move_y]==0){
                    while(true){
                        move_a += dir[j][0];
                        move_b += dir[j][1];
                        if(move_a<0||move_a>=n||move_b<0||move_b>=n)break;
                        if(board[move_a][move_b]==1){
                            move_a -= dir[j][0];
                            move_b -= dir[j][1];
                            check=true;
                            break;
                        }
                    }
                }else continue;
            }
            if(check) watch.push_back({{move_x, move_y},
                             {move_a, move_b}});
        }
    }
    for(int i=0;i<watch.size()-1;i++){
        int start_x = watch[i].first.first;
        int start_y = watch[i].first.second;
        int end_x = watch[i].second.first;
        int end_y = watch[i].second.second;
        for(int j=i+1;j<watch.size();j++){
            int start_a = watch[j].first.first;
            int start_b = watch[j].first.second;
            int end_a = watch[j].second.first;
            int end_b = watch[j].second.second;
            if(start_x-end_x!=0&&(start_a>=min(start_x,end_x)&&start_a<=max(start_x,end_x))&&(start_y>=min(start_b,end_b)&&start_y<=max(start_b,end_b))){
                if(twin.count(watch[i])>0){
                    block++;
                }else twin.insert(watch[i]);
                watch.erase(watch.begin() + j, watch.begin() + j + 1);
                j--;
            }
            if(start_y-end_y!=0&&(start_b>=min(start_y,end_y)&&start_b<=max(start_y,end_y))&&(start_x>=min(start_a,end_a)&&start_x<=max(start_a,end_a))){
                if(twin.count(watch[i])>0){
                    block++;
                }else twin.insert(watch[i]);
                watch.erase(watch.begin() + j, watch.begin() + j + 1);
                j--;
            }
            if(start_x==end_x&&start_y==end_y){
                if(start_a-end_a!=0&&(start_x>=min(start_a,end_a)&&start_x<=max(start_a,end_a))&&(start_b>=min(start_y,end_y)&&start_b<=max(start_y,end_y))){
                    if(twin.count(watch[i])>0){
                        block++;
                    }else twin.insert(watch[i]);
                    watch.erase(watch.begin() + j, watch.begin() + j + 1);
                    j--;
                }
                if(start_b-end_b!=0&&(start_y>=min(start_b,end_b)&&start_y<=max(start_b,end_b))&&(start_a>=min(start_x,end_x)&&start_a<=max(start_x,end_x))){
                    if(twin.count(watch[i])>0){
                        block++;
                    }else twin.insert(watch[i]);
                    watch.erase(watch.begin() + j, watch.begin() + j + 1);
                    j--;
                }
                if(start_a==end_a&&end_b==start_b&&(start_x==start_a&&end_x==end_b)){
                    if(twin.count(watch[i])>0){
                        block++;
                    }else twin.insert(watch[i]);
                    watch.erase(watch.begin() + j, watch.begin() + j + 1);
                    j--;
                }
            }
        }
    }
    if(watch.size()+block>3){
        cout<<"NO";
    } else cout << "YES";
}