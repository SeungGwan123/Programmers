#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int c1=0;
    int c2=0;
    bool check;
    for(int i=0;i<goal.size();i++){
        check = true;
        if(goal[i]==cards1[c1]){
            c1++;
            check = false;
        }
        if(goal[i]==cards2[c2]){
            c2++;
            check = false;
        }
        if(check){
            answer = "No";
            break;
        }
    }
    if(answer.length()==0){
        answer="Yes";
    }
    return answer;
}