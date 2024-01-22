#include <bits/stdc++.h>

using namespace std;

int main() {
    int a;int b;int x;int y;
    cin>>x>>y>>a>>b;
    int A[301][301]={0,};
    //fill(&A[0][0],&A[x-1][y],-1);
    vector<int> B[a+x];
    for(int i=0;i<a+x;i++){
        for(int j=0;j<b+y;j++){
            int temp;
            cin>>temp;
            B[i].push_back(temp);
        }
    }
    for(int s=0;s<20;s++){
        for(int i=0;i<a+x;i++){
            for(int j=0;j<b+y;j++){
                if(i>=x||j>=y) {
                    if(B[i][j]==0)continue;
                    A[i-a][j-b]=B[i][j];
                }else if(i<a||j<b){
                    A[i][j]=B[i][j];
                }else{
                    if(A[i-a][j-b]!=0) A[i][j]=B[i][j]-A[i-a][j-b];
                    if(A[i][j]!=0) A[i-a][j-b]=B[i][j]-A[i][j];
                }
            }
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}