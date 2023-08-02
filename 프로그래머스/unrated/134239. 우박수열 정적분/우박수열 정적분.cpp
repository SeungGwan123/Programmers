#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<double> rain;
    vector<double> rainbow;
    long long F = k;
    //우박
    while(F!=1){
        rain.push_back(F);
        if(F%2==0){
            F = F/2;
        }else{
            F = F*3+1;
        }
    }
    rain.push_back(1);
    
    int rain_size = rain.size();
    //넓이
    rainbow.push_back(0);
    for(long i=0;i<rain_size-1;i++){
        rainbow.push_back(((rain[i]+rain[i+1])/2)+rainbow[i]);
    }
    
    //계산
    for(long i=0;i<ranges.size();i++){
        //예외처리
        //start>ranges.size() || end<0
        if(ranges[i][0]>=rainbow.size()||(rain_size-1+ranges[i][1])<0){
            answer.push_back(-1.0);
            continue;
        }
        double start = rainbow[ranges[i][0]];
        double end = rainbow[rain_size-1+ranges[i][1]];
        if(end-start<0){
            answer.push_back(-1.0);    
        }else if(end == start){
            answer.push_back(0.0);
        }
        else{
            answer.push_back(end-start);
        }
    }
    return answer;
}