#include <string>
#include <vector>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll result = 10000000000;
ll visited[100001]={0,};
void dfs(ll a,ll num,ll y){
    if(result<=num)return;
    if(visited[a]==0)visited[a]=num;
    else{
        if(num<=visited[a])visited[a]=num;
        else return;
    }
    if(a==y){
        result = min(result, num);
        return;
    }
    if(a<y) {
        if (a!=0&&2 * a < 100001 && (visited[2 * a] == 0 || num < visited[2 * a])) dfs(2*a, num, y);
        if (a+1 < 100001 && (visited[a+1] == 0 || num < visited[a+1])) dfs(a+1, num+1, y);
        if (a-1 >=0 && (visited[a-1] == 0 || num < visited[a-1])) dfs(a-1, num+1, y);
    }else{
        if (a-1 >=0 && (visited[a-1] == 0 || num < visited[a-1])) dfs(a-1, num+1, y);
    }
}
int main(){
    ll x;ll y;
    cin>>x>>y;
    dfs(x,0,y);
    cout<<result;
}