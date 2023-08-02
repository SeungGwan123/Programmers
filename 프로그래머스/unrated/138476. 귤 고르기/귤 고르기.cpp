#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector<int> orange;
    sort(tangerine.begin(),tangerine.end());
    for(int i=0;i<tangerine.size();i++){
        int now = tangerine[i];
        int count=1;
        while(tangerine[i+1]==now){ 
            i++;
            count++;
        }
        orange.push_back(count);
    }
    sort(orange.begin(),orange.end(),greater<>());
    int total=0;
    for(int i=0;i<orange.size();i++){
        cout<<orange[i];
        if(total+orange[i]<k){
            total+=orange[i];
        }else{
            answer=i+1;
            break;
        }
    }
    return answer;
}