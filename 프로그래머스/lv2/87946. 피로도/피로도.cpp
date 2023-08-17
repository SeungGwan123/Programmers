#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
//냅색?
bool visited[5001];
int final_result=0;
void backtracking(int k,int result,vector<vector<int>> dun){
    for(int i=0;i<dun.size();i++){
        int tired = dun[i][0];
        int use = dun[i][1];
        if(k<tired||visited[i]==true)continue;
        k-=use;
        result++;
        visited[i]=true;
        final_result = max(final_result,result);
        //cout<<result<<" "<<i<<" "<<k<<"\n";
        backtracking(k,result,dun);
        k+=use;
        result--;
        visited[i]=false;
    }
    return;
}
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    fill(visited,visited+5000,false);
    backtracking(k,0,dungeons);
    
    return final_result;
}