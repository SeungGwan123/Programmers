#include <string>
#include <vector>

using namespace std;
int min_tired=10000000000;
int max_picks=0;
int backtracking(vector<int> picks,vector<string>minerals,int num_pick,int num_mineral,int tired){
    if(num_pick>=max_picks||num_mineral>=minerals.size()){
        if(tired<min_tired)min_tired=tired;
        return min_tired;
    }
    if(picks[0]>0){
        picks[0]--;
        num_pick++;
        int temp_tired=0;
        int temp_mineral=0;
        for(int i=0;i<5;i++){
            if(num_mineral>=minerals.size()||tired>min_tired){
                if(tired<min_tired)min_tired=tired;
                return min_tired;
            }
            if(minerals[num_mineral][0]=='d'){
                tired++;
                temp_tired++;
            }else if(minerals[num_mineral][0]=='i'){
                tired++;
                temp_tired++;
            }else{
                tired++;
                temp_tired++;
            }
            num_mineral++;
            temp_mineral++;
        }
        backtracking(picks,minerals,num_pick,num_mineral,tired);
        picks[0]++;
        num_pick--;
        num_mineral-=temp_mineral;
        tired-=temp_tired;
    }
    if(picks[1]>0){
        picks[1]--;
        num_pick++;
        int temp_tired=0;
        int temp_mineral=0;
        for(int i=0;i<5;i++){
            if(num_mineral>=minerals.size()||tired>min_tired){
                if(tired<min_tired)min_tired=tired;
                return min_tired;
            }
            if(minerals[num_mineral][0]=='d'){
                tired+=5;
                temp_tired+=5;
            }else if(minerals[num_mineral][0]=='i'){
                tired++;
                temp_tired++;
            }else{
                tired++;
                temp_tired++;
            }
            num_mineral++;
            temp_mineral++;
        }
        backtracking(picks,minerals,num_pick,num_mineral,tired);
        picks[1]++;
        num_pick--;
        num_mineral-=temp_mineral;
        tired-=temp_tired;
    }
    if(picks[2]>0){
        picks[2]--;
        num_pick++;
        int temp_tired=0;
        int temp_mineral=0;
        for(int i=0;i<5;i++){
            if(num_mineral>=minerals.size()||tired>min_tired){
                if(tired<min_tired)min_tired=tired;
                return min_tired;
            }
            if(minerals[num_mineral][0]=='d'){
                tired+=25;
                temp_tired+=25;
            }else if(minerals[num_mineral][0]=='i'){
                tired+=5;
                temp_tired+=5;
            }else{
                tired++;
                temp_tired++;
            }
            num_mineral++;
            temp_mineral++;
        }
        backtracking(picks,minerals,num_pick,num_mineral,tired);
        picks[2]++;
        num_pick--;
        num_mineral-=temp_mineral;
        tired-=temp_tired;
    }
    return min_tired;
}
int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    for(int i=0;i<picks.size();i++){
        max_picks+=picks[i];
    }
    return backtracking(picks,minerals,0,0,0);
    
}