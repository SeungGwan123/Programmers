import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Integer.parseInt(br.readLine());
        List<Integer> dice = new ArrayList<>();
        long one = 50;
        long total = 0;
        long one_max = 0;
        String[] dice_data = br.readLine().split(" ");
        for(int i=0;i<6;i++){
            dice.add(Integer.parseInt(dice_data[i]));
            one = Math.min(one,dice.get(i));
            one_max = Math.max(one_max,dice.get(i));
            total += dice.get(i);
        }
        long two = 100;
        long three = 150;
        int[][] adjacentPairs = {
                {0,1},{0,2},{0,3},{0,4},{1,2},{1,3},{1,5},{2,4},{2,5},{3,4},{3,5},{4,5}
        };
        for (int[] p : adjacentPairs) {
            two = Math.min(two, dice.get(p[0]) + dice.get(p[1]));
        }
        int[][] cornerTriples = {
                {3, 0, 4},
                {3, 0, 1},
                {3, 1, 5},
                {3, 4, 5},
                {2, 0, 4},
                {2, 0, 1},
                {2, 1, 5},
                {2, 4, 5}
        };
        for (int[] t : cornerTriples) {
            three = Math.min(three,
                    dice.get(t[0]) + dice.get(t[1]) + dice.get(t[2])
            );
        }
        if(n>2) System.out.println(one*((n-2)*(n-1)*4+(n-2)*(n-2))+two*(((n-1)*4)+(n-2)*4)+three*4);
        else if(n==2) System.out.println(two*4+three*4);
        else System.out.println(total-one_max);
        //System.out.println(three);
    }
}