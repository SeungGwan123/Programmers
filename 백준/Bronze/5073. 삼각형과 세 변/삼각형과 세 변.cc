#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(){
    while(true){
        int a;int b;int c;
        cin>>a>>b>>c;
        if(a==0&&b==0&&c==0)break;
        int d = a+b+c;
        int e = max(a,max(b,c));
        if(d-e<=e) cout<<"Invalid"<<endl;
        else if(a==b&&b==c) cout<<"Equilateral"<<endl;
        else if(a==b||b==c||c==a)cout<<"Isosceles"<<endl;
        else cout<<"Scalene"<<endl;
    }
}