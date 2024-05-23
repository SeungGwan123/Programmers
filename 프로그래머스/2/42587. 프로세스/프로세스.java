import java.util.*;
class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        Queue<Integer> q = new LinkedList<>();
        Queue<Integer> qq = new LinkedList<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int i=0;i<priorities.length;i++){
            q.add(priorities[i]);
            qq.add(i);
            pq.add(priorities[i]);
        }
        while(!q.isEmpty()){
            if(pq.peek()!=q.peek()){
                pq.add(pq.poll());
                q.add(q.poll());
                qq.add(qq.poll());
                //answer++;
            }else{
                if(location == qq.peek()) {
                    answer++;
                    break;
                }else{
                    answer++;
                    pq.poll();
                    q.poll();
                    qq.poll();
                }
            }
        }
        return answer;
    }
}