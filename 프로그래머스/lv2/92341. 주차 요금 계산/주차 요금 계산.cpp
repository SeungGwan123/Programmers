#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int origin_time = fees[0];
    int origin_fee = fees[1];
    int time = fees[2];
    int fee = fees[3];
    map<int,int> park;
    map<int,int> car_all;
    vector<pair<int,int>> car_list;
    bool park_check[10000]={0,};
    for(int i=0;i<records.size();i++){
        string now = records[i];
        int car_time = (int)(now[0]-48)*10*60+(int)(now[1]-48)*60+(int)(now[3]-48)*10+(int)(now[4]-48);
        int car_number = (int)(now[6]-48)*1000+(int)(now[7]-48)*100+(int)(now[8]-48)*10+(int)(now[9]-48);
        char state = now[11];
        int charge=0;
        //cout<<car_time<<" "<<car_number<<"\n";
        if(state == 'I'){
            park_check[car_number]=true;
            if(park.count(car_number)==0) park.insert({car_number,car_time});
            else park[car_number]=car_time;
        }else{
            int charge_time = car_time-park[car_number];
            // if(charge_time>0){
            //     if(charge_time%time!=0)charge_time = charge_time/time+1;
            //     else charge_time = charge_time/time;
            // }else charge_time = 0;
            //charge = charge_time*fee+origin_fee;
            park.erase(car_number);
            if(car_all.count(car_number)==0){
                car_all.insert({car_number,charge_time});
                car_list.push_back({car_number,charge_time});
                cout<<car_number<<" "<<charge<<"\n";
            }else{
                for(int i=0;i<car_list.size();i++){
                    if(car_list[i].first==car_number){
                        car_list[i].second+=charge_time;
                        break;
                    }
                }
                cout<<car_number<<" "<<charge<<"\n";
            }
        }
    }
    for(auto iter = park.begin();iter!=park.end();iter++){
        int temp_number = iter->first;
        int temp_time = iter->second;
        int temp_fee = 1439-temp_time;
        // if(temp_fee<0)temp_fee = 0;
        // if(temp_fee%time!=0)temp_fee = temp_fee/time+1;
        // else temp_fee = temp_fee/time;
        // temp_fee = temp_fee*fee+origin_fee;
        if(car_all.count(temp_number)>0){
            for(int i=0;i<car_list.size();i++){
                if(car_list[i].first==temp_number){
                    car_list[i].second+=temp_fee;
                    break;
                }
            }
        }else car_list.push_back({temp_number,temp_fee});
        cout<<temp_number<<" "<<temp_fee<<"\n";
    }
    sort(car_list.begin(),car_list.end());
    for(int i=0;i<car_list.size();i++){
        int result = car_list[i].second-origin_time;
        if(result>0){
            if(result%time!=0){
                result = result/time+1;
            }else result = result/time;
        }else result=0;
        result = result*fee+origin_fee;
        answer.push_back(result);
    }
    return answer;
}