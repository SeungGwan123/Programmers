import java.util.*;
class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        for(int i=0;i<speeds.length;i++){
            int work = 100 - progresses[i];
            int date = work / speeds[i];
            if(work%speeds[i]>0)date+=1;
            speeds[i] = date;
        }
        List<Integer> list = new ArrayList<>();
        int count = 0;
        int now = speeds[0];
        for(int i=0;i<speeds.length;i++){
            if(now<speeds[i]){
                list.add(count);
                count=1;
                now = speeds[i];
            }else{
                count++;
            }
        }
        list.add(count);
        int[] answer = new int[list.size()];
        for(int i=0;i<list.size();i++){
            answer[i] = list.get(i);
        }
        return answer;
    }
}