#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    answer.push_back(-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> result;
    int temp=0;
    for(int i=1;i<numbers.size();i++){
        answer.push_back(-1);
        if(numbers[i-1]<numbers[i]){
            answer[i-1]=numbers[i];
        }else{
            result.push({numbers[i-1],i-1});
        }
        while(!result.empty()){
            int count = result.top().first;
            int num = result.top().second;
            if(count>=numbers[i])break;
            result.pop();
            answer[num]=numbers[i];
        }
    }
    return answer;
}
