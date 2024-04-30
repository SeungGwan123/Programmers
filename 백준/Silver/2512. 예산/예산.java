// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
import java.util.*;
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> num = new ArrayList<>();
        int max=0;
        int min =0;
        for(int i=0;i<n;i++){
            num.add(sc.nextInt());
            max = Math.max(max, num.get(i));
            //min = Math.min(min, num.get(i));
        }
        int m = sc.nextInt();
        int mid = (max + min) / 2;
        Collections.sort(num);
        while(true){
            int sum = 0;
            for(int i=0;i<n;i++){
                int now = num.get(i);
                if(now<mid){
                    sum += now;
                }else sum+=mid;
            }
            if(max<=min){
                if(sum>m) System.out.println(mid - 1);
                else System.out.println(mid);
                break;
            }
            if(sum>m){
                max = mid-1;
            }else if(sum==m){
                System.out.println(mid);
                break;
            }else{
                min = mid+1;
            }
            mid = (max + min) / 2;
        }
    }
}