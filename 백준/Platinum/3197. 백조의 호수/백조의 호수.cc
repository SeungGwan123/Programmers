#include <bits/stdc++.h>

using namespace std;
vector<int> lake;
//원래 자기 자신이 부모. 연결되면서 부모를 정함
void init(int i)
{
    lake[i] = i;
}
//부모를 찾는 함수 (이렇게 구하는걸 경로 압축이라고 한다)
//모든 경로가 부모를 가르키게 함
//상수 시간의 복잡도를 가짐
int Find(int x)
{
    if (lake[x] == x) return x;
    return lake[x] = Find(lake[x]);
}
//두 노드를 연결 시키는 것
//기준을 정해서 연결시키는 것이 헷갈리지 않음
//작은쪽이 부모 or 큰쪽이 부모
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x != y)
    {
        if (x < y)
            lake[y] = x;
        else
            lake[x] = y;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r;int c;
    cin>>r>>c;
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    vector<int> board[r];
    int swan1 = -1;
    int swan2 = -1;
    vector<bool> visited[r];
    for(int i=0;i<r;i++){
        string temp;
        cin>>temp;
        for(int j=0;j<c;j++){
            if(temp[j]=='.') board[i].push_back(-1);
            else if(temp[j]=='X') board[i].push_back(-2);
            else  board[i].push_back(-3);
            visited[i].push_back(false);
        }
    }
    queue<tuple<int,int,int>> water;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(visited[i][j]||board[i][j]==-2||board[i][j]>=0) continue;
            int num = lake.size();
            lake.push_back(num);
            init(num);
            visited[i][j]=true;
            queue<pair<int,int>> q;
            queue<tuple<int,int>> meet;
            q.push({i, j});
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(board[x][y]==-3){
                    if(swan1==-1) swan1=num;
                    else swan2=num;
                }
                board[x][y]=lake[num];
                for(int d=0;d<4;d++){
                    int a = x + dir[d][0];
                    int b = y + dir[d][1];
                    if(a<0||a>=r||b<0||b>=c) continue;
                    if(visited[a][b]||board[a][b]==num)continue;
                    if(board[a][b]==-2){
                        //meet.push({a, b});
                        water.push({a, b, lake[num]});
                        visited[a][b]=true;
                        //board[a][b]=num;
                        continue;
                    }
                    visited[a][b]=true;
                    q.push({a, b});
                }
            }
            //water.push_back(meet);
        }
    }

//    if(swan1==swan2){
//        cout << "0";
//        return 0;
//    }
    int turn=0;
    //fill_n(&visited[0][0], r * c, false);
    while(true){
//        if(true) {
//            cout << "turn : " << turn << endl;
//            for (int i = 0; i < r; i++) {
//                for (int j = 0; j < c; j++) {
//                    if (board[i][j] == swan1 || board[i][j] == swan2)cout << "*";
//                    else if (board[i][j] >= 0)cout << ".";
//                    else cout << "1";
//                }
//                cout << endl;
//            }
//            cout << endl;
//        }
//        int s1 = swan1; int n1 = lake[swan1];
//        while(true){
//            if(lake[s1]==lake[n1]) break;
//            else{
//                lake[s1] = min(lake[s1],lake[n1]);
//                lake[n1] = min(lake[s1],lake[n1]);
//                s1 = n1;
//                n1 = lake[s1];
//            }
//        }
//        s1 = swan2; n1 = lake[swan2];
//        while(true){
//            if(lake[s1]==lake[n1]) break;
//            else{
//                lake[s1] = min(lake[s1],lake[n1]);
//                lake[n1] = min(lake[s1],lake[n1]);
//                s1 = n1;
//                n1 = lake[s1];
//            }
//        }
//        if(lake[swan1]==lake[swan2]) break;
        if(Find(swan1)==Find(swan2)) break;
        queue<tuple<int, int,int>> temp;
        while (!water.empty()) {
            int x;
            int y;
            int num;
            tie(x, y,num) = water.front();
            water.pop();
            board[x][y] = lake[num];
            for (int d = 0; d < 4; d++) {
                int a = x + dir[d][0];
                int b = y + dir[d][1];
                if (a < 0 || a >= r || b < 0 || b >= c)continue;

                //if (visited[a][b])continue;
                if (board[a][b] == -2 && !visited[a][b]) {
                    temp.push({a, b,lake[num]});
                    visited[a][b] = true;
                    //board[a][b] = board[x][y];
                    continue;
                }
                if (board[a][b] >= 0 && lake[board[x][y]] != lake[board[a][b]]) {
                    Union(board[x][y], board[a][b]);
//                    int now_num = board[x][y];
//                    int next_num = board[a][b];
//                    lake[now_num] = min(lake[now_num], lake[next_num]);
//                    lake[next_num] = min(lake[now_num], lake[next_num]);
//                        if(lake[swan1]==lake[swan2]) {
//                            cout<<++turn;
//                            return 0;
//                        }
                }
            }
        }
        water = temp;
        turn++;
    }
    cout<<turn;
}
