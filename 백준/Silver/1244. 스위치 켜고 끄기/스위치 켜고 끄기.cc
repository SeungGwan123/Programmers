#include <bits/stdc++.h>

using namespace std;
vector<int> light;
void man(int x){
    int num=x;
    while(true){
        if(num>=light.size())return;
        if(light[num]==0)light[num]=1;
        else light[num]=0;
        num+=x;
    }
    return;
}
void woman(int x){
    int start=x;
    int end = x;
    while(true){
        if(start<=0||end>=light.size())return;
        if(light[start]==light[end]){
            if(start==end){
                if(light[start]==0)light[start]=1;
                else light[start]=0;
            }else{
                if(light[start]==0)light[start]=1;
                else light[start]=0;
                if(light[end]==0)light[end]=1;
                else light[end]=0;
            }
        }else return;
        start--;
        end++;
    }
}
int main() {
    int s;
    cin>>s;

    light.push_back(-1);
    for(int i=0;i<s;i++){
        int temp;
        cin>>temp;
        light.push_back(temp);
    }
    int c;
    cin>>c;
    for(int i=0;i<c;i++){
        int a;int b;
        cin>>a>>b;
        if(a==1){
            man(b);
        } else woman(b);
    }
    for(int i=1;i<light.size();i++){
        cout<<light[i]<<" ";
        if(i%20==0&&i!=light.size()-1) cout<<endl;
    }
}
