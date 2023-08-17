#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> answer;
    for(long long i=left;i<=right;i++){
        long long result = i/n;
        for(long long j=i%n;j<n&&i<=right;j++,i++){
            if(result>=j){
                answer.push_back(result+1);
            }else{
                answer.push_back(j+1);
            }
            //cout<<i<<" ";
        }
        i--;
    }
    return answer;
}