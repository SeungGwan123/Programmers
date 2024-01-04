#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<string> gem = gems;
    sort(gem.begin(),gem.end());
    gem.erase(unique(gem.begin(),gem.end()),gem.end());
    int num = gem.size();
    int small = 100001;
    int start=0;int end = 0;int temp_end=0;int temp_start=0;
    set<string> s;
    map<string,int> m;
    int count=0;
    while(temp_end!=gems.size()){
        if(small==num-1)break;
        for(;temp_end<gems.size();temp_end++){
            if(s.count(gems[temp_end])==0){
                count++;
                s.insert(gems[temp_end]);
                m[gems[temp_end]]=1;
            }else m[gems[temp_end]]++;
            if(count==num){

                temp_end++;
                break;
            }
        }
        //temp_end--;
        for(;temp_start<temp_end;temp_start++){
            m[gems[temp_start]]--;
            if(m[gems[temp_start]]==0){
                count--;
                s.erase(gems[temp_start]);
                if(temp_end-temp_start<small&&count==num-1){
                    end = temp_end;
                    start=temp_start+1;
                    small = temp_end-temp_start;
                }
                temp_start++;
                break;
            }
        }
        //temp_start--;
    }
    answer.push_back(start);
    answer.push_back(end);
    return answer;
}
