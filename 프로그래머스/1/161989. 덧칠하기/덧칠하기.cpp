#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    sort(section.begin(),section.end());
    int paint = 0;
    for(int i=0;i<section.size();i++){
        int start = section[i];
        if(start>paint){
            answer++;
            paint = start+m-1;
        }
    }
    return answer;
}