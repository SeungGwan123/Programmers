#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a;
    cin>>a;
    if(a>=90) cout<<"A";
    else if(a>=80) cout<<"B";
    else if(a>=70) cout<<"C";
    else if(a>=60) cout<<"D";
    else cout << "F";
}
