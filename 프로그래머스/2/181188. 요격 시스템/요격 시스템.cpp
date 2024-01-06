#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
bool compare(vector<int> a,vector<int> b){
    if(a[0] == b[0]) {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}
int solution(vector<vector<int>> targets) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long answer=0;
    int end = -1;
    sort(targets.begin(),targets.end(),compare);
    for(long long i=0;i<targets.size();i++){
        //cout<<targets[i][0]<<" "<<targets[i][1]<<endl;
        if(end<=targets[i][0]){
            answer++;
            end=targets[i][1];
        }else end = min(end,targets[i][1]);
    }
    return answer;
}