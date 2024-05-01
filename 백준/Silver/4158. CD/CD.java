// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
import java.util.*;
import java.io.*;
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true) {
            StringTokenizer stk = new StringTokenizer(br.readLine()," ");
            int n = Integer.parseInt(stk.nextToken());
            int m = Integer.parseInt(stk.nextToken());
            if(n==0&&m==0) break;
            int result = 0;
            Set<Integer> sg = new HashSet(n);
            for (int i = 0; i < n; i++) {
                sg.add(Integer.parseInt(br.readLine()));
            }
            for (int i = 0; i < m; i++) {
                if (sg.contains(Integer.parseInt(br.readLine()))) {
                    result++;
                }
            }
            System.out.println(result);
        }
    }
}