#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
//    set<int> s;
//    map<int,int> m;
    vector<int> s[n+1];
//    vector<int> m[2001];
//    vector<int> sm[n+1][2001];
    int total = 0;
    priority_queue<tuple<int,int,int>> v;
    vector<int> result;
    for(int i=0;i<n;i++){
        int a;int b;
        cin>>a>>b;
        v.push({b,a,i});
        result.push_back(0);
        total+=b;
        if(s[a].size()==0) s[a].push_back(b);
        else s[a][0]+=b;
//        if(m[b].size()==0) m[b].push_back(b);
//        else m[b][0]+=b;
//        if(sm[a][b].size()==0) sm[a][b].push_back(b);
//        else sm[a][b][0]+=b;
    }
    //sort(v.begin(), v.end(),greater<>());
    queue<pair<int,int>> qq;
    int temp_v[200001];
    fill_n(temp_v, n + 1, 0);
    int temp_size=-1;
    int temp_tt_size=0;
    while(!v.empty()){
        int size;int color;int num;
        tie(size,color,num) = v.top();
        v.pop();
        if(temp_size!=size){
            while(!qq.empty()){
                int temp_n;int temp_c;
                tie(temp_n,temp_c) = qq.front();
                qq.pop();
                result[temp_n]-=(temp_tt_size-temp_v[temp_c]);
                temp_tt_size-=temp_size;
                temp_v[temp_c]-=temp_size;
            }
            fill_n(temp_v, n + 1, 0);
            temp_size = size;
            temp_tt_size+=size;
            temp_v[color]+=size;
            qq.push({num,color});
        }else{
            qq.push({num,color});
            temp_tt_size+=size;
            temp_v[color]+=size;
        }
        result[num]=total-s[color][0];
        s[color][0]-=size;
        total-=size;
    }
    while(!qq.empty()){
        int temp_n;int temp_c;
        tie(temp_n,temp_c) = qq.front();
        qq.pop();
        result[temp_n]-=(temp_tt_size-temp_v[temp_c]);
        temp_tt_size-=temp_size;
        temp_v[temp_c]-=temp_size;
    }
    for(int i=0;i<n;i++){
        cout<<result[i]<<"\n";
    }
}