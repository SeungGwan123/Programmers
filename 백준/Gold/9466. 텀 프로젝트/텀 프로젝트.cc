#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int result=0;
bool visited[100000];
bool check = false;
int v[100000];
set<int> s;
map<int,int> m;
void dfs(int now,int start,int count){
    if(visited[now]) {
        //check = true;
        //visited[now]=false;
        return;
    }
    visited[now]=true;
    int next = v[now];
    if(next==now) {
        //visited[now]=false;
        //check = true;
        return;
    }
    else{
        if(s.count(next)>0){
            result+=(count+1-m[next]);
            return;
        }else{
            s.insert(next);
            m[next]=count+1;
            dfs(next, start, count + 1);
            //if(check) visited[now]=false;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for(int N=0;N<n;N++){
        int num;
        result=0;
        cin>>num;
        fill_n(visited, num, false);
        fill_n(v, num, 0);
        for(int i=0;i<num;i++){
            int temp;
            cin>>temp;
            v[i]= (temp - 1);
        }
        for(int i=0;i<num;i++){
            check = false;
            if(v[i]==i){
                result++;
                visited[i]=true;
                continue;
            }
            if(visited[i])continue;
            s.clear();
            m.clear();
            s.insert(i);
            m[i]=1;
            dfs(i, i, 1);
            //if(check) visited[i]=true;
        }
        cout<<num-result<<endl;
    }
}
