#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> topping) {
    int answer = -1;
    int result=0;
    vector<int> one(topping.begin(),topping.begin()+(topping.size()/2));
    vector<int> two(topping.begin()+(topping.size()/2),topping.end());
    sort(one.begin(),one.end());
    sort(two.begin(),two.end());
    vector<int> temp1[10001];
    vector<int> temp2[10001];
    vector<int> temp11[10001];
    vector<int> temp22[10001];
    int one_size=0;int two_size=0;
    for(int i=0;i<one.size();i++){
        int now = one[i];
        if(temp1[now].size()==0){
            temp1[now].push_back(1);
            temp11[now].push_back(1);
            one_size++;
        }else{
            temp1[now][0]++;
            temp11[now][0]++;
        }
    }
    for(int i=0;i<two.size();i++){
        int now = two[i];
        if(temp2[now].size()==0){
            temp2[now].push_back(1);
            temp22[now].push_back(1);
            two_size++;
        }else{
            temp2[now][0]++;
            temp22[now][0]++;
        }
    }
    int o_size = one_size; int t_size = two_size;
    if(one_size==two_size)result++;
    for(int i=topping.size()/2;i<topping.size();i++){
        if(temp11[topping[i]].size()==0){
            o_size++;
            temp11[topping[i]].push_back(1);
        }else if(temp11[topping[i]][0]==0){
            o_size++;
            temp11[topping[i]][0]++;
        }else{
            temp11[topping[i]][0]++;
        }
        temp22[topping[i]][0]--;
        if(temp22[topping[i]][0]==0){
            t_size--;
        }
        if(o_size==t_size)result++;
        if(o_size>t_size)break;
    }
    for(int i=topping.size()/2-1;i>=0;i--){
        if(temp2[topping[i]].size()==0){
            two_size++;
            temp2[topping[i]].push_back(1);
        }else if(temp2[topping[i]][0]==0){
            two_size++;
            temp2[topping[i]][0]++;
        }else{
            temp2[topping[i]][0]++;
        }
        temp1[topping[i]][0]--;
        if(temp1[topping[i]][0]==0){
            one_size--;
        }
        if(two_size==one_size)result++;
        if(two_size>one_size)break;
    }
    answer=result;
    return answer;
}