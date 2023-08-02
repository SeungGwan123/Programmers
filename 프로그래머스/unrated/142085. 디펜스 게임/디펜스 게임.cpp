#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int answer = 0;
    priority_queue<int> defence;
    int total=0;
    for(int i=0;i<enemy.size();i++){
        bool check = false;
        if(total+enemy[i]<=n){
            total+=enemy[i];
            defence.push(enemy[i]);
        }else{
            defence.push(enemy[i]);
            while(k>0){
                k--;
                if(defence.size()>0){
                    total-=defence.top();
                    defence.pop();
                }
                if(total+enemy[i]<=n){
                    total+=enemy[i];
                    check=true;
                    break;
                }
            }
            if(check!=true){
                answer=i;
                break;
            }
        }
    }
    if(answer==0){
        answer=enemy.size();
    }
    return answer;
}