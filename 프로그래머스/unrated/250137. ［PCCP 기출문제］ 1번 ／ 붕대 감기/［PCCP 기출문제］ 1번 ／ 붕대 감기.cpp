#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int now=0;
    int max_h=health;
    int total = bandage[0];
    int heal = bandage[1];
    int bonus = bandage[2];
    int monster=0;
    for(int i=1;i<=attacks[attacks.size()-1][0];i++){
        int at = attacks[monster][0];
        int damage = attacks[monster][1];
        if(i==at){
            now=0;
            health-=damage;
            monster++;
        }else{
            now++;
            health+=heal;
            if(health>max_h)health=max_h;
            if(now==total){
                now=0;
                health+=bonus;
                if(health>max_h)health=max_h;
            }
        }
        if(health<=0){
            answer=-1;
            break;
        }
    }
    if(answer!=-1){
        answer = health;
    }
    return answer;
}