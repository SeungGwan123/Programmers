#include <string>
#include <vector>

using namespace std;
bool check(vector<vector<string>> places,int p,int i,int j){
    int dir_a[8] = {0,0,1,-1,1,1,-1,-1};
    int dir_b[8] = {1,-1,0,0,1,-1,1,-1};
    int dir[2]={2,-2};
    for(int c=0;c<8;c++){
        int direction_a = i+dir_a[c];
        int direction_b = j+dir_b[c];
        if(direction_a<0||direction_a>4||direction_b<0||direction_b>4)continue;
        if(c>3){
            if(places[p][direction_a][direction_b]=='P'&&(
                places[p][i][direction_b]=='O'||places[p][direction_a][j]=='O')) return false;    
        }else{
            if(places[p][direction_a][direction_b]=='P') return false;
        }
    }
    for(int c=0;c<2;c++){
        int a = i+dir[c];
        if(a<0||a>4)continue;
        if(places[p][a][j]=='P'&&places[p][(a+i)/2][j]=='O')return false;
    }
    for(int c=0;c<2;c++){
        int a = j+dir[c];
        if(a<0||a>4)continue;
        if(places[p][i][a]=='P'&&places[p][i][(a+j)/2]=='O')return false;
    }
    return true;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    bool temp = true;
    for(int p=0;p<places.size();p++){
        for(int i=0;i<places[p].size();i++){
            for(int j=0;j<places[p][i].length();j++){
                if(places[p][i][j]=='P'){
                    temp = check(places,p,i,j);
                    if(temp==false)break;
                }
            }
            if(temp==false)break;
        }
        if(temp)answer.push_back(1);
        else {
            answer.push_back(0);
            temp=true;
        }
    }
    return answer;
}