#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int result=10000000;
vector<int> v[1000001];
void bt(int x,int y,int n,int c){
    queue<pair<int,int>> q;
    q.push({x,c});
    while(!q.empty()){
        int num = q.front().first;
        int count = q.front().second;
        q.pop();
        if(num==y){
            result = count;
            break;
        }
        for(int i=3;i>=1;i--){
            if(i==1 && num+n<=1000000){
                if(v[num+n].size()==0) {
                    v[num+n].push_back(count+1);
                    q.push({num+n,count+1});
                }
                else{
                    if(v[num+n][0]<count+1)continue;
                    else{
                        v[num+n][0] = count+1;
                        q.push({num+n,count+1});
                    }
                }
            }else{
                if(num*i>1000000)continue;
                if(v[num*i].size()==0){
                    v[num*i].push_back(count+1);
                    q.push({num*i,count+1});
                }
                else{
                    if(v[num*i][0]<count+1)continue;
                    else{
                        v[num*i][0] = count+1;
                        q.push({num*i,count+1});
                    }
                }
            }
        }
    }
}
int solution(int x, int y, int n) {
    int answer = 0;
    v[x].push_back(0);
    bt(x,y,n,0);
    if(result==10000000)answer=-1;
    else answer = result;
    return answer;
}
