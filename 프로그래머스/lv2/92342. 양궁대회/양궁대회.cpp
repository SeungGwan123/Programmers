#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<int> result;
long result_score=0;
long score=1;
void backtracking(long n,vector<int> peach, vector<int> lion,long peach_score,long lion_score){
    for(int i=0;i<peach.size();i++){
        if(i==10){
            lion[i] = n;
            n=0;
        }
        if(n==0){
            if(lion_score-peach_score>=score){
                //result_score = lion_score;
                result = lion;
                score = lion_score-peach_score;
                //cout<<score<<" ";
            }
            return;
        }
        if(n-peach[i]-1<0||lion[i]!=0)continue;
        lion[i] += (peach[i]+1);
        n = n-(peach[i]+1);
        lion_score+=(10-i);
        //if(peach[i]!=0)lion_score+=(10-i);
        if(peach[i]!=0)peach_score-=(10-i);
        backtracking(n,peach,lion,peach_score,lion_score);
        lion[i] -= (peach[i]+1);
        n = n+peach[i]+1;
        lion_score-=(10-i);
        //if(peach[i]!=0)lion_score-=(10-i);
        if(peach[i]!=0)peach_score+=(10-i);
    }
    return;
}
vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> lion;
    long peach_score=0;
    for(int i=0;i<11;i++){
        lion.push_back(0);
        result.push_back(0);
        if(info[i]!=0)peach_score+=(10-i);
    }
    bool check=false;
    
    backtracking(n,info,lion,peach_score,0);
    for(int i=0;i<10;i++){
        if(result[i]!=0){
            check=true;
            break;
        }
    }
    if(check) answer = result;
    else answer.push_back(-1);
    return answer;
}