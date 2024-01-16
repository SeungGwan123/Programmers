#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;

int main(){
    ll n;string line;ll result=-10000000000000;
    cin>>n>>line;
    queue<vector<ll>> num;
    queue<vector<ll>> f;
    //0 + 1 - 2 *
    vector<ll> temp_num;
    vector<ll> temp_f;
    for(ll i=0;i<n;i++){
        if(i%2==0) temp_num.push_back((ll)line[i]-48);
        else{
            char temp = line[i];
            if(temp=='+') temp_f.push_back(0);
            else if(temp=='-') temp_f.push_back(1);
            else temp_f.push_back(2);
        }
    }
    if(temp_num.size()==1){
        cout<<temp_num[0];
        return 0;
    }
    num.push(temp_num);
    f.push(temp_f);
    set<pair<vector<ll>,vector<ll>>> s;
    while(!num.empty()) {
        vector<ll> t_num = num.front();num.pop();
        vector<ll> t_f = f.front();f.pop();
        for (ll j = 0; j < t_num.size() - 1; j++) {
            vector<ll> now_num = t_num;
            vector<ll> now_f = t_f;
            if(now_f[j]==0){
                now_num[j]=now_num[j]+now_num[j+1];
                now_num.erase(now_num.begin()+j+1,now_num.begin()+j+2);
                now_f.erase(now_f.begin()+j,now_f.begin()+j+1);
            }else if(now_f[j]==1){
                now_num[j]=now_num[j]-now_num[j+1];
                now_num.erase(now_num.begin()+j+1,now_num.begin()+j+2);
                now_f.erase(now_f.begin()+j,now_f.begin()+j+1);
            }else{
                now_num[j]=now_num[j]*now_num[j+1];
                now_num.erase(now_num.begin()+j+1,now_num.begin()+j+2);
                now_f.erase(now_f.begin()+j,now_f.begin()+j+1);
            }
            if(now_num.size()==1){
                result=max(result,now_num[0]);
            }else{
                if(s.count({now_num,now_f})==0){
                    s.insert({now_num,now_f});
                    num.push(now_num);
                    f.push(now_f);
                }
            }
        }
    }
    cout<<result;
}