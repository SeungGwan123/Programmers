#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
//완탐말고 dp나 다른 방법이 없을까...?
int solution(vector<int> elements) {
    int answer = 0;
    set<int> s;
    for(int i=1;i<=elements.size();i++){
        vector<int> array = elements;
        array.insert(array.end(),elements.begin(),elements.begin()+i-1);
        for(int j=0;j<elements.size();j++){
            int temp=0;
            for(int z=0;z<i;z++){
                temp+=array[j+z];
            }
            //cout<<temp<<" ";
            s.insert(temp);
        }        
        //cout<<"\n";
    }
    answer= s.size();
    return answer;
}