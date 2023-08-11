#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long answer = 1000000000;
    long sum_1 = 0;
    long sum_2 = 0;
    for(int i=0;i<queue1.size();i++){
        sum_1+= queue1[i];
    }
    for(int i=0;i<queue2.size();i++){
        sum_2+=queue2[i];
    }
    long same = (sum_1+sum_2)/2;
    long count=0;
    //cout<<same<<"\n";
    if((sum_1+sum_2)%2==1)answer=-1;
    else{
        //cout<<sum_1<<" "<<sum_2;
            long first=0;
            long second=0;
            for(int i=0;i<queue2.size()*2+queue1.size();i++){
                
                if(sum_1==same){
                    //cout<<"1\n";
                    answer = min(answer,count);
                    break;
                }
                else if(sum_1>same){
                    count++;
                    if(first>=queue1.size()+queue2.size()) sum_1-=queue1[first-queue1.size()-queue2.size()];
                    else if(first>=queue1.size()) sum_1-=queue2[first-queue1.size()];
                    
                    else sum_1-=queue1[first];
                    first++;
                }else{
                    if(second>=queue2.size()+queue1.size()) sum_1+=queue2[second-queue2.size()-queue1.size()];
                    else if(second>=queue2.size()) sum_1+=queue1[second-queue2.size()];
                    else sum_1+=queue2[second];
                    second++;
                    count++;
                }
                //cout<<sum_1<<" "<<same<<"\n";
            }
            //cout<<answer<<" "<<count<<"\n";
            first=0;
            second =0;
            count=0;
            for(int i=0;i<queue1.size()*2+queue2.size();i++){
                
                
                if(sum_2==same){
                    answer = min(answer,count);
                    break;
                }else if(sum_2>same){
                    count++;
                    if(second>=queue2.size()+queue1.size()) sum_2-=queue2[second-queue2.size()-queue1.size()];
                    else if(second>=queue2.size()) sum_2-=queue1[second-queue2.size()];
                    else sum_2-=queue2[second];
                    second++;
                }else{
                    if(first>=queue1.size()+queue2.size()) sum_2+=queue1[first-queue1.size()-queue2.size()];
                    else if(first>=queue1.size()) sum_2+=queue2[first-queue1.size()];
                    else sum_2+=queue1[first];
                    first++;
                    count++;
                }
                //cout<<sum_2<<" "<<same<<"\n";
            }
    }
    if(answer==1000000000)answer=-1;
    return answer;
}