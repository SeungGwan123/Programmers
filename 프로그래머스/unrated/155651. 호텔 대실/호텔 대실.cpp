#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<pair<int,int>>customer;
    vector<int>room;
    //sort(book_time.begin(),book_time.end());
    for(int i=0;i<book_time.size();i++){
        int start;int end;
        for(int j=0;j<2;j++){
            int clock = (int)(book_time[i][j][0]-48)*10+(int)(book_time[i][j][1]-48);
            int minute = (int)(book_time[i][j][3]-48)*10+(int)(book_time[i][j][4]-48);
            if(j==0){
                start = clock*60+minute;
            }else{
                end = clock*60+minute;
            }
        }
        customer.push_back({start,end+10});
    }
    sort(customer.begin(),customer.end());
    for(int i=0;i<customer.size();i++){
        int check_in=false;
        int start;int end;
        tie(start,end) = customer[i];
        for(int j=0;j<room.size();j++){
            if(room[j]<=start){
                room[j]=end;
                check_in=true;
                break;
            }
        }
        if(check_in==false){
            room.push_back(end);
        }
    }
    return room.size();
}