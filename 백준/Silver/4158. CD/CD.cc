#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true) {
        int n;
        int m;
        cin >> n >> m;
        if(n==0&&m==0)break;
        vector<int> sg(n);
        vector<int> sy(m);
        int result = 0;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            sg[i]=temp;
        }
        for (int i = 0; i < m; i++) {
            int temp;
            cin >> temp;
            sy[i]=temp;
        }
        int g=0;
        int y=0;
        while(g<sg.size()&&y<sy.size()){
            if(sg[g]==sy[y]){
                g++;
                y++;
                result++;
            }else{
                if(sg[g]>sy[y]) y++;
                else g++;
            }
        }
        cout<<result<<endl;
    }
}
