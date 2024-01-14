#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    set<char> ss;
    map<char,int> m;
    for(int i=0;i<s.length();i++){
        char temp = s[i];
        if(ss.count(temp)==0){
            answer.push_back(-1);
            ss.insert(temp);
            m[temp]=i+1;
        }else{
            answer.push_back(i+1-m[temp]);
            m[temp]=i+1;
        }
    }
    return answer;
}