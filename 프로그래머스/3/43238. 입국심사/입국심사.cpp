#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(),times.end());
    long long max = 1000000000000000000;
    long long min = 0;
    long long mid = (max+min)/2;
    while(true){
        long long sum=0;
        for(int i=0;i<times.size();i++){
            sum += mid/times[i];
            if(sum>n)break;
        }
        if(sum>=n){
            max = mid-1;
            mid = (max+min)/2;
        }else if(sum<n){
            min = mid+1;
            mid = (max+min)/2;
        }
        if(max<=min){
            sum=0;
            for(int i=0;i<times.size();i++){
                sum += max/times[i];
            }
            if(sum==n) answer = max;
            else answer = max+1;
            break;
        }
    }
    return answer;
}