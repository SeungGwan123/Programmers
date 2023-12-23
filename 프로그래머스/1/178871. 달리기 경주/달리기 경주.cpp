#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string,int> s;
    for(int i=0;i<players.size();i++){
        s[players[i]]=i;
    }
    for(int i=0;i<callings.size();i++){
        string a = callings[i];
        int b = s[a];
        string temp = players[b-1];
        players[b-1] = a;
        players[b] = temp;
        s[temp]++;
        s[a]--;
    }
    answer = players;
    return answer;
}