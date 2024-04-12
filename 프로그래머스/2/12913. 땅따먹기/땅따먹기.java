import java.util.*;

class Solution {
    int solution(int[][] land) {
        int answer = 0;
        for(int i=1;i<land.length;i++){
            for(int j=0;j<land[i].length;j++){
                int temp = land[i][j];
                for(int z=0;z<4;z++){
                    if(z==j)continue;
                    if(temp<land[i][j]+land[i-1][z]) temp = land[i][j]+land[i-1][z];
                }
                land[i][j]=temp;
                //System.out.print(temp+" ");
                if(i==land.length-1){
                    if(answer<temp)answer = temp;
                }
            }
            //System.out.println();
        }
        
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.

        return answer;
    }
}