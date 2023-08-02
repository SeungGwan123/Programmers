#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<tuple<string,string,string>>hw;
    for(int i=0;i<plans.size();i++){
        hw.push_back({plans[i][1],plans[i][2],plans[i][0]});
    }
    sort(hw.begin(),hw.end());
    vector<tuple<int,int,string>> work;
    stack<pair<int,string>> undo;
    for(int i=0;i<hw.size();i++){
        string name;
        string start;
        string length;
        tie(start,length,name)=hw[i];
        int hour = ((int)start[0]-48)*10+((int)start[1]-48);
        int minute = ((int)start[3]-48)*10+((int)start[4]-48);
        int time = hour*60+minute;
        int Len = stoi(length);
        work.push_back({time,Len,name});
    }
    for(int i=1;i<work.size();i++){
        string name;int time;int length;
        string l_name;int l_time;int l_length;
        tie(time,length,name)=work[i];
        tie(l_time,l_length,l_name)=work[i-1];
        if(l_time+l_length==time){
            answer.push_back(l_name);
        }else if(l_time+l_length>time){
            undo.push({l_time+l_length-time,l_name});
        }else{
            answer.push_back(l_name);
            int total_time=l_time+l_length;
            while(true){
                if(undo.empty())break;
                else{
                    int un_time = undo.top().first;
                    string un_name = undo.top().second;
                    undo.pop();
                    if(total_time+un_time==time){
                        answer.push_back(un_name);
                        break;
                    }else if(total_time+un_time>time){
                        undo.push({total_time+un_time-time,un_name});
                        break;
                    }else{
                        total_time+=un_time;
                        answer.push_back(un_name);
                    }
                }
            }
        }
        if(i==work.size()-1){
            answer.push_back(name);
        }
    }
    while(!undo.empty()){
        string name = undo.top().second;
        undo.pop();
        answer.push_back(name);
    }
    return answer;
}