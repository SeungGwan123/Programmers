#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int x;int y;
    brown-=4;
    brown/=2;
    int check;
    for(int i=0;i<brown;i++){
        if(i*(brown-i)==yellow){
            check=i;
            break;
        }
    }
    check = max(check,(brown-check));
    answer.push_back(check+2);
    answer.push_back((brown-check)+2);
    return answer;
}