#include <bits/stdc++.h>

using namespace std;
bool visited[5][5];
vector<int> boo[5];
int n;int m;
int final_result=0;
int dir[4][4]={{0,-1,1,0},{0,-1,-1,0},{-1,0,0,1},{0,1,1,0}};
void bfs(int a,int b,int result){
    for(int i=0;i<n;i++){
        if(i<a)continue;
        for(int j=0;j<m;j++){
            if((i==a&&j<b)||visited[i][j])continue;
            for(int d=0;d<4;d++){
                int r_x = i+dir[d][0];
                int r_y = j+dir[d][1];
                int l_x = i+dir[d][2];
                int l_y = j+dir[d][3];
                if(r_x<0||r_x>=n||l_x<0||l_x>=n||r_y<0||r_y>=m||l_y<0||l_y>=m)continue;
                if(visited[r_x][r_y]||visited[l_x][l_y])continue;
                result+=(boo[i][j]*2+boo[r_x][r_y]+boo[l_x][l_y]);
                visited[i][j]=true;
                visited[r_x][r_y]=true;
                visited[l_x][l_y]=true;
                bfs(i, j, result);
                result-=(boo[i][j]*2+boo[r_x][r_y]+boo[l_x][l_y]);
                visited[i][j]=false;
                visited[r_x][r_y]=false;
                visited[l_x][l_y]=false;
            }
        }
    }
    final_result = max(final_result, result);
}
int main() {

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int temp;
            cin>>temp;
            boo[i].push_back(temp);
        }
    }
    fill_n(&visited[0][0], 5 * 5, false);
    bfs(0, 0,0);
    cout<<final_result;
}