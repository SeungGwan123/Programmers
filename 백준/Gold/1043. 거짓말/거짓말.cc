#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;int m;
    cin>>n>>m;
    int l;
    cin>>l;

    set<int> lie;
    set<int> lie_p;
    queue<int> lie_q;

    vector<int> p[51];
    vector<int> party[51];
    for(int i=0;i<l;i++){
        int temp;
        cin>>temp;
        lie.insert(temp);
        lie_q.push(temp);
    }
    for(int i=0;i<m;i++){
        int people;
        cin>>people;
        for(int j=0;j<people;j++){
            int temp;
            cin>>temp;
            p[temp].push_back(i);
            party[i].push_back(temp);
        }
    }
    while(!lie_q.empty()){
        int now = lie_q.front();
        lie_q.pop();
        for(int i=0;i<p[now].size();i++){
            int now_party = p[now][i];
            if(lie_p.count(now_party)==0){
                lie_p.insert(now_party);
                for(int j=0;j<party[now_party].size();j++){
                    if(lie.count(party[now_party][j])==0){
                        lie.insert(party[now_party][j]);
                        lie_q.push(party[now_party][j]);
                    }
                }
            }
        }
    }
    cout<<m-lie_p.size();
}