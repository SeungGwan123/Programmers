#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    unsigned long long a = stoull(p);
    for(int i=0;i<t.length()-p.length()+1;i++){
        string temp = "";
        for(int j=0;j<p.length();j++){
            temp+=t[i+j];
        }
        unsigned long long it = stoull(temp);
        if(it<=a)answer++;
    }
    return answer;
}