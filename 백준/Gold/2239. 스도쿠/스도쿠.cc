#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> v[9];
set<int> row[9];
set<int> column[9];
set<int> box[9];
bool check = false;
int cal_box(int i,int j){
    int num=-1;
    if(i<3){
        if(j<3) num=0;
        else if(j<6) num=1;
        else num=2;
    }else if(i<6){
        if(j<3) num=3;
        else if(j<6) num=4;
        else num=5;
    }else{
        if(j<3) num=6;
        else if(j<6) num=7;
        else num=8;
    }
    return num;
}
void back(int a,int b){
    if(check) return;
    if(v[a][b]==0){
        int temp = -1;
        for(int i=1;i<=9;i++){
            if(row[a].count(i)==0&&column[b].count(i)==0&&box[cal_box(a,b)].count(i)==0) {
                temp = i;
                row[a].insert(temp);
                column[b].insert(temp);
                box[cal_box(a,b)].insert(temp);
                v[a][b] = temp;
                if(b<8) back(a, b + 1);
                else{
                    if(a<8) back(a + 1, 0);
                    else{
                        check = true;
                        return;
                    }
                }
                if(check) return;
                v[a][b]=0;
                row[a].erase(temp);
                column[b].erase(temp);
                box[cal_box(a, b)].erase(temp);
            }
        }
    }else{
        if(b<8) back(a, b + 1);
        else{
            if(a<8) back(a + 1, 0);
            else{
                check = true;
                return;
            }
        }
    }
}
int main() {
    for(int i=0;i<9;i++){
        string temp;
        cin>>temp;
        for(int j=0;j<9;j++){
            int now = int(temp[j])-48;
            v[i].push_back(now);
            if(now!=0){
                row[i].insert(now);
                column[j].insert(now);
                box[cal_box(i, j)].insert(now);
            }
        }
    }
    back(0, 0);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }
}
