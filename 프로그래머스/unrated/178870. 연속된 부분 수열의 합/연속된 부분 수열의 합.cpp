#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int start=0;
    int f_s=0;
    int f_e=0;
    int total=0;
    int length=10000000;
    for(int i=0;i<sequence.size();i++){
        total+=sequence[i];
        if(total<k)continue;
        if(sequence[i]>k||length==1)break;
        while(total>k){
            total-=sequence[start];
            start++;
        }
        if(total==k){
            if(i-start+1<length){
                length=i-start+1;
                f_s=start;
                f_e=i;
            }
        }
    }
    answer.push_back(f_s);
    answer.push_back(f_e);
    return answer;
}