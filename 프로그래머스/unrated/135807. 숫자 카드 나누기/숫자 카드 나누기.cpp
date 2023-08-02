#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    sort(arrayA.begin(),arrayA.end());
    sort(arrayB.begin(),arrayB.end());
    for(int i=max(arrayA[0],arrayB[0]);i>0;i--){
        bool check=true;
        bool result=true;
        bool same = false;
        if(arrayA[0]%i==0&&arrayB[0]%i!=0){
            check=true;
        }else if(arrayA[0]%i!=0&&arrayB[0]%i==0){
            check=false;
        }else{
            if(arrayA[0]==arrayB[0])break;
            continue;
        }
        for(int j=1;j<arrayA.size();j++){
            if(arrayA[j]==arrayB[j]){
                same=true;
                break;
            }
            if(check==true){
                if(arrayA[j]%i!=0||arrayB[j]%i==0){
                    result=false;
                    break;
                }
            }else if(check==false){
                if(arrayA[j]%i==0||arrayB[j]%i!=0){
                    result=false;
                    break;
                }
            }
        }
        if(same)break;
        if(result==false)continue;
        else{
            answer=i;
            break;
        }
    }
    return answer;
}