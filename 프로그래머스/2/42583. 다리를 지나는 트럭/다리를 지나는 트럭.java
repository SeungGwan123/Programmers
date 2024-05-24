import java.util.*;
class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        int tw = 0;
        Queue<int []> q = new LinkedList<>();
        for(int i=0;i<truck_weights.length;i++){
            int now = truck_weights[i];
            if(tw+now<=weight){
                if(!q.isEmpty()){
                    int [] temp = q.peek();
                    if(temp[1]+(bridge_length-1)==answer){
                        tw-=temp[0];
                        q.poll();
                    }
                }
                answer++;
                tw += now;
                q.add(new int[] {now, answer});
            }else{
                int [] temp = q.poll();
                answer=temp[1]+bridge_length-1;
                tw -= temp[0];
                i--;
            }
            //System.out.println(answer+" "+q.size());
        }
        return answer+bridge_length;
    }
}