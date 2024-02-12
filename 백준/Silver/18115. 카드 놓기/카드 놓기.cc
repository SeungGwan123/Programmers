#include <bits/stdc++.h>

using namespace std;

int main() {
    int a=0;int b=1;
    int n;
    cin>>n;
    int c = n-1;
    int card[n];
    fill_n(card, n, 0);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(temp==3){
            card[c]=n-i;
            c--;
        }else if(temp==2){
            card[b]=n-i;
            b++;
        }else{
            card[a]=n-i;
            a=b;
            b++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<card[i]<<" ";
    }
}