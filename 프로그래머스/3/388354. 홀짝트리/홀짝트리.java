import java.util.*;
class Tree{
    int odd_odd;
    int odd_even;
    int even_even;
    int even_odd;
    public Tree(int odd_odd,int odd_even,int even_even,int even_odd){
        this.odd_odd = odd_odd;
        this.odd_even = odd_even;
        this.even_even = even_even;
        this.even_odd = even_odd;
    }
}
class Solution {
    public static TreeMap<Integer,Integer> map = new TreeMap<>();
    public static TreeMap<Integer,Tree> tree = new TreeMap<>();
    public int find(int a){
        int parent = map.get(a);
        if(a==parent) return parent;
        else {
            int result = find(parent);
            map.put(a,result);
            return result;
        }
    }
    public void union(int a,int b){
        int x = find(a);
        int y = find(b);
        
        if(find(a)==find(b)) return ;
        
        if(x<y){
            map.put(x,y);
        }else{
            map.put(y,x);
        }
    }
    public int[] solution(int[] nodes, int[][] edges) {
        int[] answer = {0,0};
        TreeMap<Integer,Integer> edge_count = new TreeMap<>();
        //union 객체 초기화, 근처 edge갯수 초기화
        for(int i=0;i<nodes.length;i++){
            map.put(nodes[i],nodes[i]);
            edge_count.put(nodes[i],0);
        }
        //union-find, edge갯수 세기
        for(int i=0;i<edges.length;i++){
            int a = edges[i][0];
            int b = edges[i][1];
            union(a,b);
            edge_count.put(a,edge_count.get(a)+1);
            edge_count.put(b,edge_count.get(b)+1);
        }
        List<Integer> list = new ArrayList<>();
        //tree정보 입력
        for(int i=0;i<nodes.length;i++){
            int now = find(map.get(nodes[i]));
            //System.out.println(now);
            int now_node = edge_count.get(nodes[i]);
            if(!tree.containsKey(now)){
                tree.put(now,new Tree(0,0,0,0));
                list.add(now);
            }
            Tree now_tree = tree.get(now);
            if(nodes[i]%2==0){
                if(now_node%2==0){
                    now_tree.even_even++;
                }else now_tree.even_odd++;
            }else{
                if(now_node%2==0){
                    now_tree.odd_even++;
                }else now_tree.odd_odd++;
            }
        }
        for(int i=0;i<list.size();i++){
            Tree now_tree = tree.get(list.get(i));
            //System.out.println(list.get(i)+ " "+now_tree.odd_odd+" "+now_tree.even_even+" "+now_tree.odd_even+" "+now_tree.even_odd);
            if(now_tree.odd_odd==1&&now_tree.even_even==0) answer[0]++;
            if(now_tree.odd_odd==0&&now_tree.even_even==1) answer[0]++;
            if(now_tree.odd_even==1&&now_tree.even_odd==0) answer[1]++;
            if(now_tree.odd_even==0&&now_tree.even_odd==1) answer[1]++;
        }
        return answer;
    }
}