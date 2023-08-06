#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    int box=1;
    bool check=false;
    for(int i=0;i<order.size();i++){
        for(int j=box;j<=order.size();j++,box++){
            if(order[i]==j){
                answer++;
                box++;
                break;
            }else if(!s.empty()&&s.top()==order[i]){
                answer++;
                s.pop();
                break;
            }else {
                s.push(j);
            }
            if(!s.empty()&&order[i]<s.top()&&order[i]<j){
                check=true;
                break;
            }
        }
        if(check==true)break;
        while(!s.empty()&&order[i]==s.top()){
            s.pop();
            i++;
            answer++;
        }
        //if(i!=order.size()&&box==order.size()&&order[i+1]!=s.top()) break;
    }
    return answer;
}