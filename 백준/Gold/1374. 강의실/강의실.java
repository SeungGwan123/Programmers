import java.util.*;

class data implements Comparable<data>{
    int n;
    int start;
    int end;
    public data(int n,int start,int end){
        this.n = n;
        this.start = start;
        this.end = end;
    }

    @Override
    public int compareTo(data other){
        if(this.start != other.start){
            return this.start - other.start;
        }else{
            return this.end - other.end;
        }
    }

}
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int num = sc.nextInt();
        PriorityQueue<data> pq = new PriorityQueue<>();
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        int available = 0;

        for(int i=0;i<num;i++){
            int n = sc.nextInt();
            int start = sc.nextInt();
            int end = sc.nextInt();
            pq.add(new data(n, start, end));
        }

        while(!pq.isEmpty()){
            data now = pq.poll();

            if(queue.isEmpty()){
                queue.add(now.end);
            }else{
                while(!queue.isEmpty()){
                    int time = queue.peek();
                    if(now.start>=time) queue.poll();
                    else break;
                }
                queue.add(now.end);
            }

            available = Math.max(available, queue.size());
        }

        System.out.print(available);
    }
}