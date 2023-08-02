#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    for(int i=0;i<balls.size();i++){
        int x = balls[i][0];
        int y = balls[i][1];
        int dis =1000000000;
        int temp=0;
        if(!(startY==y&&x>startX)){
            temp = pow(m+(m-x)-startX,2)+pow(y-startY,2);
            dis = min(temp,dis);
        }
        if(!(startX==x&&y>startY)){
            temp = pow(x-startX,2)+pow(n+(n-y)-startY,2);
            dis = min(temp,dis);
        }
        if(!(startY==y&&x<startX)){
            temp = pow(-x-startX,2)+pow(y-startY,2);
            dis = min(temp,dis);
        }
        if(!(startX==x&&y<startY)){
            temp = pow(x-startX,2)+pow(-y-startY,2);
            dis = min(temp,dis);
        }
        answer.push_back(dis);
    }
    return answer;
}