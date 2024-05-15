import java.util.*;
class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        Map<String,Integer> m = new HashMap<>();
        for(int i=0;i<clothes.length;i++){
            String key = clothes[i][1];
            m.put(key,m.getOrDefault(key,0)+1);
        }
        List<Integer> list = new ArrayList<>();
        for(Map.Entry<String,Integer> entry : m.entrySet()){
            list.add(entry.getValue()+1);
        }
        for(int i=0;i<list.size();i++){
            answer*=list.get(i);
        }
        return answer-1;
    }
}