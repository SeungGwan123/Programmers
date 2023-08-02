#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

long long solution(int r1, int r2) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long answer=0;
    for(int x=1;x<r2;x++){
        long long big_r = sqrt(pow(r2,2)-pow(x,2));
        double small_r=0;
        if(x<r1){
            small_r = sqrt(pow(r1,2)-pow(x,2));
        }
        int small_temp=small_r;
        if(small_r!=0&&small_r==small_temp){
            small_temp--;
            answer+=(big_r-small_temp);
        }else{
            answer+=(big_r-small_temp);
        }
    }
    answer+=(r2-r1+1);
    answer=answer*4;
    return answer;
}