#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for(int i=0;i*k<=d;i++){
        int length = sqrt(pow(d,2)-pow(i*k,2));
        answer+=length/k+1;
    }
    return answer;
}