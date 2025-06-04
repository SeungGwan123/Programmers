import java.util.*;

class Solution {
    public static int[][] visited;
    public static int[][] picture;
    public static int[][] dir = new int[][]{{1,0},{-1,0},{0,1},{0,-1}};
    public static int bfs(int x,int y,int m,int n){
        int result = 1;
        visited[x][y] = 1;
        int section_num = picture[x][y];
        Queue<Integer[]> q = new LinkedList<>();
        q.add(new Integer[]{x,y});
        while(!q.isEmpty()){
            Integer[] now = q.poll();
            for(int d=0;d<4;d++){
                int a = now[0]+dir[d][0];
                int b = now[1]+dir[d][1];
                if(a<0||a>=m||b<0||b>=n) continue;
                if(visited[a][b]==1||section_num!=picture[a][b]) continue;
                visited[a][b] = 1;
                result++;
                q.add(new Integer[]{a,b});
            }
        }
        return result;
    }
    public int[] solution(int m, int n, int[][] pictures) {    
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;
        visited = new int[m][n];
        picture = pictures;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0){
                    int area = bfs(i,j,m,n);
                    if(picture[i][j]==0) continue;
                    numberOfArea++;
                    maxSizeOfOneArea = Math.max(maxSizeOfOneArea,area);
                }
                else continue;
            }
        }
        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }
}