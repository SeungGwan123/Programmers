import java.util.*;

public class Main{
    public static int n;
    public static int m;

    public static int min_water = 30;
    public static int p = 30;
    public static int[] water = new int[p];
    public static int init(){
        int power = p;
        int result = 0;
        while(n>0 && power >=0){
            int w2p = (int)Math.pow(2,power);
            if(n - w2p >= 0){
                water[power] = 1;
                result ++;
                n -= w2p;
                min_water = Math.min(min_water, power);
            }else{
                power--;
            }
        }
        return result;
    }
    public static int sum(){
        int next = min_water;
        int result = 0;
        for(int i=min_water+1;i<p;i++){
            if(water[i]!=0){
                next = i;
                break;
            }
        }
        result = (int)Math.pow(2,next) - (int)Math.pow(2,min_water);
        water[min_water]--;
        water[next]++;
        while(water[next]==2){
            if(water[next+1]==1){
                water[next] = 0;
                water[next+1] = 2;
            }else{
                min_water = next+1;
                water[next+1] = 1;
                water[next] = 0;
            }
            next++;
        }
        return result;
    }
    public static int check(){
        int result = 0;
        for(int i=0;i<p;i++){
            result += water[i];
        }
        return result;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        if(n==m) {
            System.out.println(0);
            return;
        }
        int bottle = init();
        int result = 0;
        while(bottle>m){
            result += sum();
            if(check()<=m) break;
        }
        System.out.println(result);
    }
}
