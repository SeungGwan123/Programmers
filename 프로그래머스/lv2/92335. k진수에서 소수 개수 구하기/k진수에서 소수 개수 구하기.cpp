#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int n, int k) {
    long answer = 0;
    stack<long> s;
    vector<long> num;
    set<long> ss;
    while(n!=0){
        long temp = n%k;
        n/=k;
        s.push(temp);
    }
    while(!s.empty()){
        num.push_back(s.top());
        s.pop();
    }
    
    for(long i=1;i<=num.size();i++){
        for(long j=0;j<num.size()-(i-1);j++){
            long temp=-1;
            if(j==0){
                if(j+i==num.size()){
                    temp=0;
                    for(long z=j;z<j+i;z++){
                        if(num[z]==0){
                            temp=-1;
                            break;
                        }
                        temp*=10;
                        temp+=num[z];
                    }
                }else{
                    if(num[j+i]==0){
                       temp=0;
                        for(long z=j;z<j+i;z++){
                            if(num[z]==0){
                                temp=-1;
                                break;
                            }
                            temp*=10;
                            temp+=num[z];
                        } 
                    }else continue;
                }
            }else if(j==num.size()-1){
                if(num[j-1]==0){
                    if(num[j]==0)temp=-1;
                    else temp=num[j];
                }else continue;
            }else{
                if(j+i==num.size()){
                    if(num[j-1]==0){
                        temp=0;
                        for(long z=j;z<j+i;z++){
                            if(num[z]==0){
                                temp=-1;
                                break;
                            }
                            temp*=10;
                            temp+=num[z];
                        } 
                    }else continue;
                }else{
                    if(num[j-1]==0&&num[j+i]==0){
                        temp=0;
                        for(long z=j;z<j+i;z++){
                            if(num[z]==0){
                                temp=-1;
                                break;
                            }
                            temp*=10;
                            temp+=num[z];
                        } 
                    }else continue;
                }
            }
            if(temp==-1||temp==1)continue;
            bool check=false;
            if(ss.count(temp)==0){
                for(long s=2;s<=sqrt(temp);s++){
                    if(temp%s==0){
                        check=true;
                        break;
                    }
                }
            }
            if(!check){
                //cout<<temp<<" "<<i<<" "<<j<<"\n";
                ss.insert(temp);
                answer++;
            }
        }
    }
    return answer;
}