import java.util.*;

class Solution {
    //d l r u
    public static int[][] dir = new int[][]{{1,0},{0,-1},{0,1},{-1,0}};
    public static char[] dir_char = new char[]{'d','l','r','u'};
    public static int k;
    public static int n;
    public static int m;
    public static int r;
    public static int c;
    public static String result = "";
    public void bfs(int x,int y,int count,String route){
        int min_dist = Math.abs(r-x)+Math.abs(c-y);
        
        if(!result.equals("")) return;
        if(count==k){
            if(x==r&&y==c){
                result = route;
            }
            return ;
        }
        //System.out.println(route);
        if(min_dist>k-count||(k-count-min_dist)%2!=0){
            return;
        }
        for(int d=0;d<4;d++){
            int a = x+dir[d][0];
            int b = y+dir[d][1];
            if(a<0||b<0||a>=n||b>=m) continue;
            
            bfs(a,b,count+1,route+dir_char[d]);
        }
    }
    public String solution(int nn, int mm, int x, int y, int rr, int cc, int kk) {
        String answer = "";
        k = kk;
        n = nn;
        m = mm;
        r = rr-1;
        c = cc-1;
        //PriorityQueue<String> pq = new PriorityQueue<>();
        bfs(x-1,y-1,0,"");
        //System.out.println(pq.peek());
        if(result.equals("")) answer = "impossible";
        else answer = result;
        return answer;
    }
}