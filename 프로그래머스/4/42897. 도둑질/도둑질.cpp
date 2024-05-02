#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    vector<int> yes(money.size());
    vector<int> no(money.size());
    vector<int> check(money.size());
    yes[0]=(money[0]);
    no[0]=(0);
    check[0]=(1);
    for(int i=1;i<money.size();i++){
        if(check[i-1]==1&&yes[i-1]>no[i-1]) check[i]=(1);
        else{
            if(check[i-1]==2||no[i-1]>yes[i-1]) check[i]=(2);
            else check[i]=(0);
        }
        yes[i]=(no[i-1]+money[i]);
        no[i]=(max(yes[i-1],no[i-1]));
    }
    if(check[check.size()-1]==0) answer = max(yes[yes.size()-1],no[no.size()-1]);
    else answer = no[no.size()-1];
    vector<int> Yes(money.size());
    vector<int> No(money.size());
    vector<int> Check(money.size());
    Yes[0]=(money[money.size()-1]);
    No[0]=(0);
    Check[0]=(1);
    for(int i=money.size()-2,j=1;i>=0;i--,j++){
        if(Check[j-1]==1&&Yes[j-1]>No[j-1]) Check[j]=(1);
        else{
            if(Check[j-1]==2||No[j-1]>Yes[j-1]) Check[j]=(2);
            else Check[j]=(0);
        }
        Yes[j]=(No[j-1]+money[i]);
        No[j]=(max(Yes[j-1],No[j-1]));
    }
    if(Check[Check.size()-1]==0) answer = max(answer,max(Yes[Yes.size()-1],No[No.size()-1]));
    else answer = max(answer,No[No.size()-1]);
    //answer = max(yes[yes.size()-1],max(no[no.size()-1],max(Yes[Yes.size()-1],No[No.size()-1])));
    // cout<<"yes no \n";
    // for(int i=0;i<yes.size();i++){
    //     cout<<yes[i]<<" "<<no[i]<<endl;
    // }
    // cout<<"Yes No \n";
    // for(int i=0;i<Yes.size();i++){
    //     cout<<Yes[i]<<" "<<No[i]<<endl;
    // }
    return answer;
}