import java.util.*;

class pair implements Comparable<pair>{
    int x;
    int y;
    int i;
    pair left_child = null;
    pair right_child = null;
    pair parent = null;
    public pair(int x,int y,int i){
        this.x = x;
        this.y = y;
        this.i = i;
    }
    
    @Override
    public int compareTo(pair p){
        if(this.y==p.y) return this.x - p.x;
        else return p.y - this.y;
    }
}
class Solution {
    public static List<Integer> front = new ArrayList<>();
    public static List<Integer> back = new ArrayList<>();
    public static List<pair> list;
    public static int n;
    public void makeTree(pair p,int p_num){
        pair now = list.get(p_num);
        if(p.x<now.x){
            if(p.right_child==null){
                p.right_child = now;
                now.parent = p;
            }else makeTree(p.right_child,p_num);
        }else{
            if(p.left_child==null){
                p.left_child = now;
                now.parent = p;
            }else makeTree(p.left_child,p_num);
        }
    }
    public void frontorder(pair p){
        front.add(p.i);
        if(p.left_child!=null){
            frontorder(p.left_child);
        }
        if(p.right_child!=null){
            frontorder(p.right_child);
        }
    }
    public void backorder(pair p){
        if(p.left_child!=null){
            backorder(p.left_child);
        }
        if(p.right_child!=null){
            backorder(p.right_child);
        }
        back.add(p.i);
    }
    public List<List<Integer>> solution(int[][] nodeinfo) {
        List<List<Integer>> answer = new ArrayList<>();
        list = new ArrayList<>();
        
        n = nodeinfo.length;
        //분할 정복
        for(int i=0;i<nodeinfo.length;i++){
            list.add(new pair(nodeinfo[i][0],nodeinfo[i][1],i+1));
        }
        Collections.sort(list);

        for(int i=1;i<list.size();i++){
            makeTree(list.get(0),i);
        }
        
        frontorder(list.get(0));
        backorder(list.get(0));
        answer.add(front);
        answer.add(back);
        return answer;
    }
}