#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    set<string> s;
    map<string,int> m;
    for(int i=0;i<name.size();i++){
        s.insert(name[i]);
        m[name[i]]=yearning[i];
    }
    for(int i=0;i<photo.size();i++){
        int temp=0;
        for(int j=0;j<photo[i].size();j++){
            if(s.count(photo[i][j])>0){
                temp+=m[photo[i][j]];
            }
        }
        answer.push_back(temp);
    }
    return answer;
}