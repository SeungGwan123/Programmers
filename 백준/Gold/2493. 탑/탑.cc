#include <string>
#include <vector>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll num;
    cin>>num;
    vector<ll> v;
    vector<ll> tower;
    for(int i=0;i<num;i++){
        ll temp;
        cin>>temp;
        v.push_back(temp);
        tower.push_back(0);
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> high;
    for(ll i=num-1;i>=1;i--){
        ll now = v[i];
        ll forward = v[i-1];
        while(!high.empty()){
            ll temp = high.top().second;
            ll height = high.top().first;
            if(forward>height){
                tower[temp]=i;
                high.pop();
            }else break;
        }
        if(forward>now)tower[i]=i;
        else{
            high.push({v[i],i});
        }
    }
    for(int i=0;i<tower.size();i++){
        cout<<tower[i]<<" ";
    }
}