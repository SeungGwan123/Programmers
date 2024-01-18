#include <bits/stdc++.h>

using namespace std;

int main(){
    //0 [-1,0] up , 1 [1,0] down, 2 [0,-1] left, 3 [0,1] right
    int n;int k;int r;
    cin>>n>>k>>r;
    int answer=0;
    int road[101][101][4];
    int cow[101][101];
    bool visited[101][101];
    vector<int> cow_group;
    int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    fill(&cow[0][0],&cow[100][101],0);
    fill(&visited[0][0],&visited[100][101],0);
    fill(&road[0][0][0],&road[100][100][4],-1);
    for(int i=0;i<r;i++){
        int a_x;int a_y;int b_x;int b_y;
        int a_d;int b_d;
        cin>>a_x>>a_y>>b_x>>b_y;
        if(a_x==b_x){
            if(a_y<b_y){
                a_d = 3;
                b_d = 2;
            }else{
                a_d = 2;
                b_d = 3;
            }
        }else{
            if(a_x<b_x){
                a_d = 1;
                b_d = 0;
            }else{
                a_d = 0;
                b_d = 1;
            }
        }
        road[a_x][a_y][a_d]=1;
        road[b_x][b_y][b_d]=1;
    }
    for(int i=0;i<k;i++){
        int x;int y;
        cin>>x>>y;
        cow[x][y]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(visited[i][j])continue;
            visited[i][j]=true;
            queue<pair<int,int>> q;
            q.emplace(i,j);
            int cows=0;
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(cow[x][y]!=0)cows+=cow[x][y];
                for(int a=0;a<4;a++){
                    if(road[x][y][a]==1) continue;
                    int t_x = x+dir[a][0];
                    int t_y = y+dir[a][1];
                    if(t_x<1||t_x>n||t_y<1||t_y>n) continue;
                    if(visited[t_x][t_y]) continue;
                    q.emplace(t_x,t_y);
                    visited[t_x][t_y]=true;
                }
            }
            if(cows!=0) cow_group.push_back(cows);
        }
    }

    for(int i=0;i<cow_group.size()-1;i++){
        for(int j=i+1;j<cow_group.size();j++){
            answer+=(cow_group[i]*cow_group[j]);
        }
    }
    cout<<answer;
}