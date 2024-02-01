#include <bits/stdc++.h>

using namespace std;
vector<int> light;

int main() {
    //하 우 상 좌
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    int n;int m;int A;int B;
    cin>>m>>n>>A>>B;
    int board[100][100];
    fill_n(&board[0][0], 100 * 100, -1);
    vector<tuple<int,int,int>> robot;
    for(int i=0;i<A;i++){
        int x;int y;char d;
        cin>>y>>x>>d;
        if(d=='S') robot.push_back({x - 1, y - 1, 2});
        else if(d=='N') robot.push_back({x - 1, y - 1, 0});
        else if(d=='W') robot.push_back({x - 1, y - 1, 3});
        else robot.push_back({x - 1, y - 1, 1});
        board[x-1][y-1]=i;
    }
    for(int i=0;i<B;i++){
        int r;char o;int num;
        cin>>r>>o>>num;
        int x;int y;int d;
        tie(x,y,d)=robot[r-1];

        if(o!='F'){
            num%=4;
            if(o=='L'){
                get<2>(robot[r-1])-=num;
                if(get<2>(robot[r-1])<0)get<2>(robot[r-1])+=4;
            }else{
                get<2>(robot[r-1])+=num;
                if(get<2>(robot[r-1])>=4)get<2>(robot[r-1])%=4;
            }
        }else{
            for(int j=0;j<num;j++){
                int a = x+ dir[d][0];
                int b = y+ dir[d][1];
                if(a<0||a>=n||b<0||b>=m){
                    cout<<"Robot "<<r<<" crashes into the wall";
                    return 0;
                }
                if(board[a][b]>=0){
                    cout<<"Robot "<<r<<" crashes into robot "<<board[a][b]+1;
                    return 0;
                }
                board[x][y]=-1;
                board[a][b]=r-1;
                x = a;
                y = b;
            }
            get<0>(robot[r-1])=x;
            get<1>(robot[r-1])=y;
        }

    }
    cout<<"OK";
}
