import java.util.*;

class Solution {
    public List<Integer> solution(int n) {
        List<Integer> answer = new ArrayList<>();
        //n = 1;
        int[][] board = new int[n][n];
        int num = 1;
        int dir = 0;
        int floor = n-1;
        int right = 0;
        int top = 1;
        int x = 0;
        int y = 0;
        //boolean check = true;
        while(true){
            if(x>=n||y>=n) break;
            if(board[x][y]!=0) break;
            board[x][y] = num++;
            if(dir==0){
                x++;
                if(x==floor) dir = 1; 
            }else if(dir==1){
                y++;
                if(y==x-right){
                    dir = 2;
                    floor--;
                    right++;
                }
            }else{
                x--;
                y--;
                if(board[x][y]!=0){
                    x+=2;
                    y++;
                    dir=0;
                    top++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                answer.add(board[i][j]);
            }
        }
        return answer;
    }
}