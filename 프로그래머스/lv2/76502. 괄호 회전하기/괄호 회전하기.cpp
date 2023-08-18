#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int answer = 0;
    for(int i=0;i<s.length();i++){
        int a=0;int b=0;int c=0;bool check=true;bool first = true;int order=0;
        for(int j=0;j<s.length();j++){
            char now = s[j];
            if(now=='['){
                a++;
                order=1;
            }
            if(now=='{'){
                b++;
                order=2;
            }
            if(now=='('){
                c++;
                order=3;
            }
            if(now==']'){
                if(first){
                    first=false;
                    if(order!=1){
                        check=false;
                        break;
                    }
                }
                if(a>0)a--;
                else{
                    check=false;
                    break;
                }
            }
            if(now=='}'){
                if(first){
                    first=false;
                    if(order!=2){
                        check=false;
                        break;
                    }
                }
                if(b>0)b--;
                else{
                    check=false;
                    break;
                }
            }
            if(now==')'){
                if(first){
                    first=false;
                    if(order!=3){
                        check=false;
                        break;
                    }
                }
                if(c>0)c--;
                else{
                    check=false;
                    break;
                }
            }
        }
        if(check&&(a==0&&b==0&&c==0))answer++;
        //cout<<s[0];
        s+=s[0];
        s = s.substr(1,s.length()-1);
    }
    return answer;
}