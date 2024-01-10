#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin>> num;
    if(num>3) {
        int temp = num/3;
        num%=3;
        if(temp%2==0){
            if(num==0)cout<<"CY";
            else if(num==1)cout<<"SK";
            else if(num==2)cout<<"CY";
        }else{
            if(num==0)cout<<"SK";
            else if(num==1)cout<<"CY";
            else if(num==2)cout<<"SK";
        }
    }else{
        if(num==1)cout<<"SK";
        else if(num==2)cout<<"CY";
        else if(num==3)cout<<"SK";
    }
}