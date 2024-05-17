import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        List<Integer> list = new ArrayList<>();
        int a = -1;
        for(int i=0;i<arr.length;i++){
            if(a!=arr[i]){
                a=arr[i];
                list.add(a);
            }
        }
        int[] answer = new int[list.size()];
        for(int i=0;i<list.size();i++){
            answer[i] = list.get(i);
        }
        return answer;
    }
}