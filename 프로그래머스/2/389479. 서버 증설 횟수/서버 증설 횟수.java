import java.util.*;

class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i=0;i<players.length;i++){
            while(!pq.isEmpty()){
                if(pq.peek()<i) pq.poll();
                else break;
            }
            int num = players[i];
            int server = num/m - pq.size();
            for(int j=0;j<server;j++){
                pq.add(i+k-1);
                answer++;
            }
        }
        return answer;
    }
}