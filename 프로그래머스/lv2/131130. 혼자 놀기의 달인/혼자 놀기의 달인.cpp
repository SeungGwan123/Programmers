#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int result=0;
void backtracking(vector<int> cards,bool visited[],int one,int two){
    for(int i=0;i<cards.size();i++){
        vector<int> temp;
        int j=i;
        while(visited[j]==false){
            temp.push_back(j);
            visited[j]=true;
            j=cards[j]-1;
        }
        if(temp.size()==cards.size())return;
        cout<<temp.size()<<" ";
        if(one!=0){
            two = temp.size();
            if(result>one*two){
                for(int z=0;z<temp.size();z++){
                    visited[temp[z]]=false;
                }
                continue;
                //backtracking(cards,visited,one,0);
            }else{
                result = max(result,(one*two));
                for(int z=0;z<temp.size();z++){
                    visited[temp[z]]=false;
                }
                continue;
            }
        }else{
            one = temp.size();
            backtracking(cards,visited,one,0);
            one=0;
            for(int z=0;z<temp.size();z++){
                visited[temp[z]]=false;
            }
        }
    }
    return;
}
int solution(vector<int> cards) {
    int answer = 0;
    bool visited[101];
    fill(visited,visited+100,false);
    backtracking(cards,visited,0,0);
    answer=result;
    return answer;
}