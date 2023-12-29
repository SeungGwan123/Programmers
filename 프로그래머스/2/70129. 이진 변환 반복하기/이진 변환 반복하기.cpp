#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int count=0;
    int zero=0;
    while(s!=""){
        regex pattern("0");
        // 대체된 문자열
        string rs = regex_replace(s, pattern, "");
        zero+=(s.length()-rs.length());

        int c = rs.length();
        s="";
        while(c>1){
            s=((char)(c%2+48))+s;
            c/=2;
            if(c<=1){
                s=((char)(c%2+48))+s;
            }
        }
        count++;
    }
    answer.push_back(count);
    answer.push_back(zero);
    return answer;
}
