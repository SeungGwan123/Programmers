#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int height;int width;
    cin>>height>>width;
    vector<int> v;
    int real=0;int tower=0;bool check_t=false;int check_i=-1;
    for(int i=0;i<width;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
        real+=temp;
        if(tower==temp){
            check_t=true;
            check_i=i;
        }
        if(tower<temp){
            check_t=false;
            tower=temp;
        }
    }
    int rain=-1;int start=0;int total=0;int result=0;
    if(check_t){
        for(int i=0;i<v.size();i++){
            int now = v[i];
            if(now>=rain){
                result += (i-start)*rain;
                rain=now;
                start=i;
            }
            if(i==check_i)break;
        }
        rain = -1;
        start = v.size() - 1;
        for (int i = v.size() - 1; i >= 0; i--) {
            int now = v[i];
            if (now >= rain) {
                result += (start - i) * rain;
                rain = now;
                start = i;
            }
            if (now == tower) {
                result += now;
                break;
            }
        }
    }else {
        for (int i = 0; i < v.size(); i++) {
            int now = v[i];
            if (now >= rain) {
                result += (i - start) * rain;
                rain = now;
                start = i;
            }
            if (now == tower)break;
        }
        rain = -1;
        start = v.size() - 1;
        for (int i = v.size() - 1; i >= 0; i--) {
            int now = v[i];
            if (now >= rain) {
                result += (start - i) * rain;
                rain = now;
                start = i;
            }
            if (now == tower) {
                result += now;
                break;
            }
        }
    }
    cout<<result-real;
}