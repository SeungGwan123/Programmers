import java.util.*;

class Solution {
    int[][] dir = new int[][]{{1,0},{-1,0},{0,1},{0,-1}};
    int total_box = 0;
    int[][] box;
    int[][] to_box;
    String[][] storage;
    int n;int m;
    int[][] visited;
    public void air(int i,int j){
        for(int d=0;d<4;d++){
            int x = i+dir[d][0];
            int y = j+dir[d][1];
            if(x<0||x>=n||y<0||y>=m) continue;
            if(visited[x][y]==1) continue;
            visited[x][y] = 1;
            if(storage[x][y].equals(" ")){
                air(x,y);
            }
            to_box[x][y] = 1;
        }
    }
    public void crain(String del_box){
        //System.out.println("crain "+del_box);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(box[i][j]==0) continue;
                if(storage[i][j].equals(del_box)){
                    total_box--;
                    storage[i][j] = " ";
                    to_box[i][j] = 0;
                    visited = new int[n][m];
                    visited[i][j] = 1;
                    air(i,j);
                }else to_box[i][j] = 1;
            }
        }
    }
    public void jege(String del_box){
        //System.out.println("jege "+del_box);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(storage[i][j].equals(del_box)){
                    total_box--;
                    storage[i][j] = " ";
                    if(box[i][j]==1||to_box[i][j]==1){
                        to_box[i][j] = 0;
                        visited = new int[n][m];
                        visited[i][j] = 1;
                        air(i,j);
                    }
                }else{
                    if(box[i][j]==1) to_box[i][j] = 1;
                }
            }
        }
    }
    public void request(String del_box){
        to_box = new int[n][m];
        int temp = total_box;
        if(del_box.length()==1) crain(del_box);
        else{
            jege(del_box.substring(0,1));
        }
        box = to_box;
    }
    public int solution(String[] storages, String[] requests) {
        int answer = 0;
        n = storages.length;
        m = storages[0].length();
        box = new int[n][m];
        storage = new String[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                total_box++;
                storage[i][j] = storages[i].substring(j,j+1);
                if(i==0||i==n-1||j==0||j==m-1){
                    box[i][j] = 1;
                }
            }
        }
        for(int i=0;i<requests.length;i++){
            request(requests[i]);
        }
        return total_box;
    }
}