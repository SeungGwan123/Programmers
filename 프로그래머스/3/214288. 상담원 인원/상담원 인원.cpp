#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0;
    vector<vector<int>> p[k];
    vector<int> teacher[k];
    vector<int> waiting[k];

    for(int i=0;i<reqs.size();i++){
        int num = reqs[i][2]-1;
        p[num].push_back(reqs[i]);
    }
    for(int i=0;i<k;i++){
        sort(p[i].begin(),p[i].end());
        teacher[i].push_back(0);
        waiting[i].push_back(0);
    }
    for(int t=0;t<n-k+1;t++){
        answer=0;
        int result=0;
        int plus;
        int s_result=0;
        int s_temp;
        for(int i=0;i<k;i++){
            for(int j=0;j<p[i].size();j++){
                int apply = p[i][j][0];
                int time = p[i][j][1];
                if(teacher[i][0]>=apply){
                    waiting[i][0]+=teacher[i][0]-apply;
                    teacher[i][0]+=time;
                }else{
                    teacher[i][0]=p[i][j][0]+p[i][j][1];
                }
                sort(teacher[i].begin(),teacher[i].end());
            }
        }
        for(int a=0;a<k;a++){
            s_temp=0;
            for(int b=0;b<teacher[a].size();b++){
                teacher[a][b]=0;
            }
            int i=a;
            teacher[a].push_back(0);
            for(int j=0;j<p[i].size();j++){
                int apply = p[i][j][0];
                int time = p[i][j][1];
                if(teacher[i][0]>=apply){
                    s_temp+=teacher[i][0]-apply;
                    teacher[i][0]+=time;
                }else{
                    teacher[i][0]=p[i][j][0]+p[i][j][1];
                }
                sort(teacher[i].begin(),teacher[i].end());
            }
            teacher[a].erase(teacher[a].end()-1,teacher[a].end());
            for(int b=0;b<teacher[a].size();b++){
                teacher[a][b]=0;
            }
            s_temp = waiting[a][0] - s_temp;
            if(s_temp>s_result){
                plus = a;
                s_result = s_temp;
            }

            answer+=waiting[a][0];
            waiting[a][0]=0;
        }
        teacher[plus].push_back(0);
    }
    return answer;
}
