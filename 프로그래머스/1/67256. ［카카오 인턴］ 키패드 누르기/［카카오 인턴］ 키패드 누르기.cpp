#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int l=-1;int r=-1;
    for(int i=0;i<numbers.size();i++){
        int now = numbers[i];
        if(now==1||now==4||now==7){
            answer+="L";
            l=now;
        }else if(now==3||now==6||now==9){
            answer+="R";
            r=now;
        }else{
            int l_len;int r_len;
            if(l==1){
                if(now==2) l_len=1;
                else if(now==5) l_len=2;
                else if(now==8) l_len=3;
                else l_len=4;
                //l=now;
            }else if(l==4){
                if(now==2) l_len=2;
                else if(now==5) l_len=1;
                else if(now==8) l_len=2;
                else l_len=3;
                //l=now;
            }else if(l==7){
                if(now==2) l_len=3;
                else if(now==5) l_len=2;
                else if(now==8) l_len=1;
                else l_len=2;
                //l=now;
            }else if(l==2){
                if(now==2) l_len=0;
                else if(now==5) l_len=1;
                else if(now==8) l_len=2;
                else l_len=3;
                //l=now;
            }else if(l==5){
                if(now==2) l_len=1;
                else if(now==5) l_len=0;
                else if(now==8) l_len=1;
                else l_len=2;
                //l=now;
            }else if(l==8){
                if(now==2) l_len=2;
                else if(now==5) l_len=1;
                else if(now==8) l_len=0;
                else l_len=1;
                //l=now;
            }else if(l==0){
                if(now==2) l_len=3;
                else if(now==5) l_len=2;
                else if(now==8) l_len=1;
                else l_len=0;
                //l=now;
            }else{
                if(now==2) l_len=4;
                else if(now==5) l_len=3;
                else if(now==8) l_len=2;
                else l_len=1;
            }
            if(r==3){
                if(now==2) r_len=1;
                else if(now==5) r_len=2;
                else if(now==8) r_len=3;
                else r_len=4;
                //r=now;
            }else if(r==6){
                if(now==2) r_len=2;
                else if(now==5) r_len=1;
                else if(now==8) r_len=2;
                else r_len=3;
                //r=now;
            }else if(r==9){
                if(now==2) r_len=3;
                else if(now==5) r_len=2;
                else if(now==8) r_len=1;
                else r_len=2;
                //r=now;
            }else if(r==2){
                if(now==2) r_len=0;
                else if(now==5) r_len=1;
                else if(now==8) r_len=2;
                else r_len=3;
                //r=now;
            }else if(r==5){
                if(now==2) r_len=1;
                else if(now==5) r_len=0;
                else if(now==8) r_len=1;
                else r_len=2;
                //r=now;
            }else if(r==8){
                if(now==2) r_len=2;
                else if(now==5) r_len=1;
                else if(now==8) r_len=0;
                else r_len=1;
                //r=now;
            }else if(r==0){
                if(now==2) r_len=3;
                else if(now==5) r_len=2;
                else if(now==8) r_len=1;
                else r_len=0;
                //r=now;
            }else{
                if(now==2) r_len=4;
                else if(now==5) r_len=3;
                else if(now==8) r_len=2;
                else r_len=1;
            }
            if(l_len<r_len){
                answer+="L";
                l=now;
            }else{
                if(r_len<l_len) {
                    answer+="R";
                    r=now;
                }
                else{
                    if(hand=="right") {
                        answer+="R";
                        r=now;
                    }else {
                        answer+="L";
                        l=now;
                    }
                }
            }
        }
    }
    return answer;
}