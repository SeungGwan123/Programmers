#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string,int> box;
    for(int i=0;i<want.size();i++){
        box.insert({want[i],number[i]});
    }
    for(int i=0;i<=discount.size()-10;i++){
        map<string,int> temp_box = box;
        bool check = true;
        for(int j=0;j<10;j++){
            string today = discount[i+j];
            //cout<<today<<" ";
            if(temp_box[today]>0){
                temp_box[today]--;
                continue;
            }else{
                check=false;
                break;  
            } 
        }
        //cout<<"\n";
        if(check)answer++;
    }
    return answer;
}