#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<int> cycle[501][501];
int len=0;
long result=0;
void backtracking(int i,int j,int z,vector<int> board[]){
    //cout<<i<<" "<<j<<" "<<z<<"\n";
    if(cycle[i][j][z]==1)return;
    if(board[i][j]==-1){//S
        if(z==0){//상
            if(i==0){
                cycle[i][j][z]=1;
                i=len-1;
                result++;
                backtracking(i,j,z,board);
            }else{
                cycle[i][j][z]=1;
                i-=1;
                result++;
                backtracking(i,j,z,board);
            }
        }else if(z==1){//하
            if(i==len-1){
                cycle[i][j][z]=1;
                i=0;
                result++;
                backtracking(i,j,z,board);
            }else{
                cycle[i][j][z]=1;
                i++;result++;
                backtracking(i,j,z,board);
            }
        }else if(z==2){//좌
            if(j==board[i].size()-1){
                cycle[i][j][z]=1;
                j=0;result++;
                backtracking(i,j,z,board);
            }else{
                cycle[i][j][z]=1;
                j++;result++;
                backtracking(i,j,z,board);
            }
        }else{//우
            if(j==0){
                cycle[i][j][z]=1;
                j=board[i].size()-1;result++;
                backtracking(i,j,z,board);
            }else{
                cycle[i][j][z]=1;
                j--;result++;
                backtracking(i,j,z,board);
            }      
        }
    }else if(board[i][j]==-2){//L
        if(z==0){//상
            if(j==0){
                cycle[i][j][z]=1;
                j=board[i].size()-1;
                z=3;result++;
                backtracking(i,j,z,board);
            }else{
                cycle[i][j][z]=1;
                j-=1;
                z=3;result++;
                backtracking(i,j,z,board);
            }
        }else if(z==1){//하
            if(j==board[i].size()-1){
                cycle[i][j][z]=1;
                j=0;z=2;result++;
                backtracking(i,j,z,board);
            }else{
                cycle[i][j][z]=1;
                j++;z=2;result++;
                backtracking(i,j,z,board);
            }
        }else if(z==2){//좌
            if(i==0){
                cycle[i][j][z]=1;
                i=len-1;z=0;result++;
                backtracking(i,j,z,board);
            }else{
                cycle[i][j][z]=1;
                i--;z=0;result++;
                backtracking(i,j,z,board);
            }
        }else{//우
            if(i==len-1){
                cycle[i][j][z]=1;
                i=0;z=1;result++;
                backtracking(i,j,z,board);
            }else{
                cycle[i][j][z]=1;
                i++;z=1;result++;
                backtracking(i,j,z,board);
            }      
        }       
    }else{//R
        if(z==0){//상
            if(j==board[i].size()-1){
                cycle[i][j][z]=1;
                j=0;z=2;
                result++;
                backtracking(i,j,z,board);
            }else{
                cycle[i][j][z]=1;
                j++;z=2;
                result++;
                backtracking(i,j,z,board);
            }
        }else if(z==1){//하
            if(j==0){
                cycle[i][j][z]=1;
                j=board[i].size()-1;z=3;
                result++;
                backtracking(i,j,z,board);
            }else{
                cycle[i][j][z]=1;
                j--;z=3;result++;
                backtracking(i,j,z,board);
            }
        }else if(z==2){//좌
            if(i==len-1){
                cycle[i][j][z]=1;
                i=0;z=1;result++;
                backtracking(i,j,z,board);
            }else{
                cycle[i][j][z]=1;
                i++;z=1;result++;
                backtracking(i,j,z,board);
            }
        }else{//우
            if(i==0){
                cycle[i][j][z]=1;
                i=len-1;z=0;result++;
                backtracking(i,j,z,board);
            }else{
                cycle[i][j][z]=1;
                i--;z=0;result++;
                backtracking(i,j,z,board);
            }      
        }   
    }
}
vector<int> solution(vector<string> grid) {
    vector<int> answer;
    vector<int> board[grid.size()];
    len=grid.size();
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].length();j++){
            cycle[i][j].push_back(0);//상
            cycle[i][j].push_back(0);//하
            cycle[i][j].push_back(0);//좌
            cycle[i][j].push_back(0);//우
            if(grid[i][j]=='S')board[i].push_back(-1);
            else if(grid[i][j]=='L')board[i].push_back(-2);
            else board[i].push_back(-3);
        }
    }
    long final_result=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].length();j++){
            for(int z=0;z<4;z++){
                if(cycle[i][j][z]==1)continue;
                //cycle[i][j][z]=1;
                backtracking(i,j,z,board);
                answer.push_back(result);
                final_result+=result;
                result=0;
                if(final_result==(len*board[0].size())*4)break;
            }
            if(final_result==(len*board[0].size())*4)break;
        }
        if(final_result==(len*board[0].size())*4)break;
    }
    sort(answer.begin(),answer.end());
    return answer;
}