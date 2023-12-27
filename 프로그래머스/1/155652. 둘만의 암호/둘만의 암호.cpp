#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
//122
string solution(string s, string skip, int index) {
    string answer = "";
    set<int> ss;
    for(int i=0;i<skip.length();i++){
        ss.insert((int)skip[i]);
    }
    for(int i=0;i<s.length();i++){
        int result;
        int jsize=index;
        for(int j=1;j<=jsize;j++){
            int temp = (int)s[i];
            int tj = temp+j;
            while(tj>122){
                tj-=26;
            }
            if(ss.count(tj)>0){
                jsize++;
                continue;
            }
            result=tj;
        }
        while(result>122){
                result-=26;
        }
        answer+=(char)result;
    }
    return answer;
}
