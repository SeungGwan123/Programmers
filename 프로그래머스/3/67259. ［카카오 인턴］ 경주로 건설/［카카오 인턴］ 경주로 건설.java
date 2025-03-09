import java.util.*;

class Solution {
    int[][] dir = new int[][]{{0,1},{0,-1},{1,0},{-1,0}};
    int[][] visited;
    int n;
    int[][] board;
    int result = 1000000000;
    public void dfs(int x,int y,int num,int count){
        if(x==n-1&&y==n-1){
            result = Math.min(result,count);
            return;
        }
        if(count>=result) return;
        for(int d=0;d<4;d++){
            int dx = x+dir[d][0];
            int dy = y+dir[d][1];
            if(dx<0||dy<0||dx>=n||dy>=n) continue;
            if(board[dx][dy]==1) continue;
            //if(visited[dx][dy]>result) continue;
            if(num!=d) {
                if(visited[dx][dy]<visited[x][y]) continue;
                visited[dx][dy] = visited[x][y]+600;
                dfs(dx,dy,d,count+600);
            }
            else{
                if(visited[dx][dy]<visited[x][y]) continue;
                visited[dx][dy] = visited[x][y]+100;
                dfs(dx,dy,d,count+100);  
            } 
        }
    }
    public int solution(int[][] input) {
        board = input;
        n = board.length;
        visited = new int[n][n];
        for(int i=0;i<n;i++){
            Arrays.fill(visited[i],1000000000);
        }
        visited[0][0]=0;
        for(int d=0;d<4;d++){
            int dx = 0+dir[d][0];
            int dy = 0+dir[d][1];
            if(dx<0||dy<0||dx>=n||dy>=n) continue;
            if(board[dx][dy]==1) continue;
            visited[dx][dy]=100;
            dfs(dx,dy,d,100);
        }
        return result;
    }
}