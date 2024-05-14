import java.util.*;
class Pair implements Comparable<Pair>{
    int first,second;
    public Pair(int first,int second){
        super();
        this.first = first;
        this.second = second;
    }
    @Override
    public int compareTo(Pair p){
        if(this.first == p.first) return Integer.compare(this.second,p.second);
        else return Integer.compare(p.first,this.first);
    }
}
class sPair implements Comparable<sPair>{
    int first;
    String second;
    public sPair(int first,String second){
        super();
        this.first = first;
        this.second = second;
    }
    @Override
    public int compareTo(sPair p){
        return Integer.compare(this.first, p.first);
    }
}
class Solution {
    public int[] solution(String[] genres, int[] plays) {
        int[] answer = {};
        List<Integer> a_list = new ArrayList<>();
        Map<String,Integer> m = new HashMap<>();
        Map<String,List<Pair>> g_m = new HashMap<>();
        for(int i=0;i<genres.length;i++){
            if(!m.containsKey(genres[i])){
                m.put(genres[i],plays[i]);
                g_m.put(genres[i],new ArrayList<>());
                g_m.get(genres[i]).add(new Pair(plays[i],i));
            }else{
                int now = m.get(genres[i]);
                m.put(genres[i],now+plays[i]);
                g_m.get(genres[i]).add(new Pair(plays[i],i));
            }
        }
        PriorityQueue<sPair> pq = new PriorityQueue<>(Collections.reverseOrder());
        Iterator<Map.Entry<String, Integer>> iterator = m.entrySet().iterator();
        while(iterator.hasNext()){
            Map.Entry<String, Integer> entry = iterator.next();
            String key = entry.getKey();
            Integer value = entry.getValue();
            pq.add(new sPair(value,key));
            //System.out.println(key+value);
        }
        while(pq.size()!=0){
            sPair sp = pq.poll();
            String g = sp.second;
            //System.out.println(g);
            Collections.sort(g_m.get(g));
            for(int i=0;i<2&&i<g_m.get(g).size();i++){
                a_list.add(g_m.get(g).get(i).second);
                //System.out.println(g_m.get(g).get(i).second);
            }
        }
        
        answer = new int[a_list.size()];
        for (int i = 0; i < a_list.size(); i++) {
            answer[i] = a_list.get(i);
        }
        return answer;
    }
}