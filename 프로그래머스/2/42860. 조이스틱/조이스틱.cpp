#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(string name) {
    int answer = 0;
    int mid = (int)'N';
    int num = 0;
    int sum=1000000000;
    vector<int> len;
    vector<int> left;
    vector<int> right;
    for(int i=0;i<name.length();i++){
        int now = (int)name[i];
        if(now<mid) len.push_back(now-65);
        else len.push_back(91-now);
        if(len[i]!=0&&i!=0) num++;
        answer+=len[i];
    }
    cout<<answer<<endl;
    for(int i=1;i<len.size();i++){
        if(len[i]!=0) right.push_back(i);
    }
    for(int i=len.size()-1;i>0;i--){
        if(len[i]!=0) left.push_back(len.size()-i);
    }
    
    for(auto iter:left){
        cout<<iter;
    }
    cout<<endl;
    for(auto iter:right){
        cout<<iter;
    }
    cout<<endl;
    
    if(num>0) sum = min(left[num-1],right[num-1]);
    int num_size;
    if((num)%2==1) num_size = num-1;
    else num_size = num-1;
    if(num>1){
        for(int i=0;i<num_size;i++){
            sum = min(sum,left[i]*2+right[num_size-i-1]);
        }
    }
    if(num>1){
        for(int i=0;i<num_size;i++){
            sum = min(sum,right[i]*2+left[num_size-i-1]);
        }
    }
    if(sum!=1000000000)answer+=sum;
    return answer;
}