#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
vector<int> v[10];
vector<pair<int,int>> horse_w;
vector<pair<int,int>> horse_b;
int visited[10][10];
int result=0;
int result_b=0;
int dir[4][2]={{1,1},{1,-1},{-1,1},{-1,-1}};
vector<vector<pair<int,int>>>  cat_w;
vector<vector<pair<int,int>>>  cat_b;
void back(int A,int value){
    result = max(result, value);
//    if(result==value){
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//                cout<<v[i][j]<<" ";
//            }
//            cout<<endl;
//        }
//        cout<<endl;
//    }
    for(int i=A;i<horse_w.size();i++){
        int a = horse_w[i].first;
        int b = horse_w[i].second;
        if(visited[a][b]>0)continue;
        visited[a][b]=1;
        for(int j=0;j<cat_w[i].size();j++){
            int x = cat_w[i][j].first;
            int y = cat_w[i][j].second;
            visited[x][y]++;
        }
        v[a][b]=2;
        back(i+1,value+1);
        v[a][b]=1;
        visited[a][b]=0;
        for(int j=0;j<cat_w[i].size();j++){
            int x = cat_w[i][j].first;
            int y = cat_w[i][j].second;
            visited[x][y]--;
        }
    }
}
void back_b(int A,int value){
    result_b = max(result_b, value);
//    cout<<"b"<<endl;
//    if(result_b==value){
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//                cout<<v[i][j]<<" ";
//            }
//            cout<<endl;
//        }
//        cout<<endl;
//    }
    for(int i=A;i<horse_b.size();i++){
        int a = horse_b[i].first;
        int b = horse_b[i].second;
        if(visited[a][b]>0)continue;
        visited[a][b]=1;
        for(int j=0;j<cat_b[i].size();j++){
            int x = cat_b[i][j].first;
            int y = cat_b[i][j].second;
            visited[x][y]++;
        }
        v[a][b]=2;
        back_b(i+1,value+1);
        v[a][b]=1;
        visited[a][b]=0;
        for(int j=0;j<cat_b[i].size();j++){
            int x = cat_b[i][j].first;
            int y = cat_b[i][j].second;
            visited[x][y]--;
        }
    }
}
int main() {
    cin>>n;
    fill_n(&visited[0][0], 10 * 10, 0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            v[i].push_back(temp);
            if(temp==1) {
                if((i+j)%2==0) {
                    horse_w.push_back({i, j});
                }else horse_b.push_back({i, j});
            }
        }
    }
    for(int i=0;i<horse_w.size();i++){
        vector<pair<int,int>> temp;
        int a = horse_w[i].first;
        int b = horse_w[i].second;
        for(int d=0;d<4;d++){
            int x = a+dir[d][0];
            int y = b+dir[d][1];
            while(true){
                if(x<0||x>=n||y<0||y>=n)break;
                if(v[x][y]==1)temp.push_back({x, y});
                x = x+dir[d][0];
                y = y+dir[d][1];
            }
        }
        cat_w.push_back(temp);
    }
    for(int i=0;i<horse_b.size();i++){
        vector<pair<int,int>> temp;
        int a = horse_b[i].first;
        int b = horse_b[i].second;
        for(int d=0;d<4;d++){
            int x = a+dir[d][0];
            int y = b+dir[d][1];
            while(true){
                if(x<0||x>=n||y<0||y>=n)break;
                if(v[x][y]==1)temp.push_back({x, y});
                x = x+dir[d][0];
                y = y+dir[d][1];
            }
        }
        cat_b.push_back(temp);
    }
    back(0, 0);
    back_b(0, 0);
    cout<<result+result_b;
}
