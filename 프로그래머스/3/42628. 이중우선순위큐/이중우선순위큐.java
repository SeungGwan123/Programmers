import java.util.*;
class Solution {
    public int[] solution(String[] operations) {
        int[] answer = {0,0};
        TreeMap<Integer,Integer> map = new TreeMap<>();
        for(int i=0;i<operations.length;i++){
            String[] oper = operations[i].split(" ");
            
            if(oper[0].equals("I")){
                int num = Integer.parseInt(oper[1]);
                if(map.containsKey(num)){
                    map.put(num,map.get(num)+1);
                }else{
                    map.put(num,1);
                }
            }else{
                if(map.isEmpty()) continue;
                if(oper[1].equals("1")){
                    Integer last = map.lastKey();
                    if(map.get(last)==1){
                        map.remove(last);
                    }else{
                        map.put(last,map.get(last)-1);
                    }
                }else{
                    Integer first = map.firstKey();
                    if(map.get(first)==1){
                        map.remove(first);
                    }else{
                        map.put(first,map.get(first)-1);
                    }
                }
            }
        }

        if(map.size()!=0) {
            Integer first = map.firstKey();
            Integer last = map.lastKey();
            answer[0] = last;
            answer[1] = first;
        }
        return answer;
    }
}