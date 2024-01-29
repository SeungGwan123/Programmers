#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;int m;
    cin>>n>>m;
    vector<int> board[n];
    vector<bool> visited[n];
    vector<set<int>> s[n];
    int result=0;
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        for(int j=0;j<m;j++){
            board[i].push_back(temp[j]-48);
            visited[i].push_back(true);
            set<int> sss;
            s[i].push_back(sss);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            queue<pair<int, int>> q;
            queue<pair<int, int>> record_q;
            if(s[i][j].count(board[i][j])>0||board[i][j]==0)continue;
            q.push({i, j});
            record_q.push({i, j});
            bool check = false;
            bool twin = false;
            int wall = 51;
            bool v_check[50][50];
            fill_n(&v_check[0][0],50*50,false);
            v_check[i][j]=true;
            while (!q.empty()) {
                int a = q.front().first;
                int b = q.front().second;
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int x = a + dir[d][0];
                    int y = b + dir[d][1];
                    if (x < 0 || x >= n || y < 0 || y >= m) {
                        check = true;
                        continue;
                    }
                    if (board[i][j] < board[x][y]) {
                        wall = min(wall, board[x][y]);
                        continue;
                    }else {
                        if (!visited[x][y]) check = true;
                    }
                    if (s[x][y].count(board[i][j]) > 0) {
                        check = true;
                        break;
                    }
                    if (board[x][y] == 0) check = true;
                    if(v_check[x][y]==true)continue;
                    q.push({x, y});
                    record_q.push({x, y});
                    v_check[x][y]=true;
                }
            }
            if (check) {
                while (!record_q.empty()) {
                    int x = record_q.front().first;
                    int y = record_q.front().second;
                    if(board[x][y]==board[i][j]) visited[record_q.front().first][record_q.front().second] = false;
                    s[record_q.front().first][record_q.front().second].insert(board[i][j]);
                    record_q.pop();
                }
            } else {
                while (!record_q.empty()) {
                    int x = record_q.front().first;
                    int y = record_q.front().second;
                    result += (wall) - board[i][j];
                    s[x][y].insert(board[i][j]);
                    record_q.pop();
                }
            }
        }
    }
    cout<<result;
}