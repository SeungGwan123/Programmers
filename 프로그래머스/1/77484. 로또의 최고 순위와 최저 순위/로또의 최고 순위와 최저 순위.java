import java.util.*;
class Solution {
    int cal(int num){
        if(num==6) return 1;
        else if(num==5) return 2;
        else if(num==4) return 3;
        else if(num==3) return 4;
        else if(num==2) return 5;
        else return 6;
    }
    public int[] solution(int[] lottos, int[] win_nums) {
        
        int result=0;
        int zero=0;
        Set<Integer> s = new HashSet<Integer>();
        for(int i=0;i<win_nums.length;i++){
            s.add(win_nums[i]);
        }
        for(int i=0;i<lottos.length;i++){
            if(s.contains(lottos[i])) result++;
            if(lottos[i]==0) zero++;
        }
        int[] answer = {cal(result+zero),cal(result)};
        return answer;
    }
}