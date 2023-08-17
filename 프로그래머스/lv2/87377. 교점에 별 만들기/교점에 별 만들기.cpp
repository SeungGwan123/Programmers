#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
bool compare(pair<long,long> a,pair<long,long> b){
    if(a.first>b.first)return true;
    else{
        if(a.second<b.second)return true;
        else return false;
    }
}
vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    set<pair<long double,long double>> spot;
    long double max_x = -1000000000000000;
    long double min_x = 1000000000000000;
    long double max_y = -1000000000000000;
    long double min_y = 1000000000000000;
    for(long i=0;i<line.size();i++){
        for(long j=i;j<line.size();j++){
            double a = line[i][0]; double b = line[i][1]; double e = line[i][2];
            double c = line[j][0]; double d = line[j][1]; double f = line[j][2];
            if(a*d-b*c==0)continue;
            long double x = (b*f-e*d)/(a*d-b*c);
            long double y = (e*c-a*f)/(a*d-b*c);
            if(x==(long)x&&y==(long)y){
                spot.insert({y,x});
                max_x = max(x,max_x);
                min_x = min(x,min_x);
                max_y = max(y,max_y);
                min_y = min(y,min_y);
            }
        }
    }
    //sort(spot.begin(),spot.end(),compare);
    //cout<<spot.size();
    long start = 0;
    for(long i=max_y;i>=min_y;i--){
        string temp="";
        for(long j=min_x;j<=max_x;j++){
            if(spot.count({i,j})!=0){
                start++;
                temp+="*";
            }else temp+=".";
        }
        answer.push_back(temp);
    }
    return answer;
}