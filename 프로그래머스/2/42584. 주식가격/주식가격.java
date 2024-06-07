import java.util.*;

class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        Stack<ArrayList<Integer>> q = new Stack<ArrayList<Integer>>();
        for(int i=0;i<prices.length;i++){
            if(!q.isEmpty()){
                while(!q.isEmpty()){
                    ArrayList<Integer> list = q.peek();
                    if(list.get(0)>prices[i]){
                        q.pop();
                        answer[list.get(1)] = i-list.get(1);
                    }else break;
                }
            }
            q.add(new ArrayList<>(Arrays.asList(prices[i],i)));
        }
        while(!q.isEmpty()){
            ArrayList<Integer> list = q.pop();
            answer[list.get(1)] = prices.length - list.get(1)-1;
        }
        return answer;
    }
}