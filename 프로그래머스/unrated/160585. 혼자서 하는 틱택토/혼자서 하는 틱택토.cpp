#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> board) {
    int answer = -1;
    int tik[3][3];
    int visited[3][3];
    int circle=0;
    bool O=false;
    bool X = false;
    int ex = 0;
    fill(&visited[0][0],&visited[2][3],0);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            char temp = board[i][j];
            if(temp=='O'){
                tik[i][j]=0;
                circle++;
            }else if(temp=='X'){
                tik[i][j]=1;
                ex++;
            }else{
                tik[i][j]=-1;
            }
        }
    }
    if(ex==circle||(circle-ex)==1){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(tik[i][j]==-1)continue;
                //visited[i][j]=1;
                if(tik[i][j]==0){
                    if(O==true)continue;
                    if(i==0&&j==0){
                        if(tik[i+1][j]==0&&tik[i+2][j]==0){
                            O=true;
                        }
                        if(tik[i+1][j+1]==0&&tik[i+2][j+2]==0){
                            O=true;
                        }
                        if(tik[i][j+1]==0&&tik[i][j+2]==0){
                            O=true;
                        }
                    }if(i==0){
                        if(tik[i+1][j]==0&&tik[i+2][j]==0){
                            O=true;
                        }
                        if(j==2){
                            if(tik[i+1][j-1]==0&&tik[i+2][j-2]==0){
                                O=true;
                            }
                        }
                    }if(j==0){
                        if(tik[i][j+1]==0&&tik[i][j+2]==0){
                            O=true;
                        }
                    }                        
                }//else if(tik[i][j]==1){
                 else{
                    if(X==true)continue;
                    if(i==0&&j==0){
                        if(tik[i+1][j]==1&&tik[i+2][j]==1){
                            X=true;
                        }if(tik[i+1][j+1]==1&&tik[i+2][j+2]==1){
                            X=true;
                        }if(tik[i][j+1]==1&&tik[i][j+2]==1){
                            X=true;
                        }
                    }else if(i==0){
                        if(tik[i+1][j]==1&&tik[i+2][j]==1){
                            X=true;
                        }
                        if(j==2){
                            if(tik[i+1][j-1]==1&&tik[i+2][j-2]==1){
                                X=true;
                            }
                        }
                    }if(j==0){
                        if(tik[i][j+1]==1&&tik[i][j+2]==1){
                            X=true;
                        }
                    }
                }
            }
        }
        if((O==true&&X==true)||(O==true&&circle!=(ex+1)&&X==false)||(O==false&&X==true&&circle!=ex)){
            answer=0;
        }else{
            answer=1;
        }
    }else{
        answer=0;
    }
    return answer;
}