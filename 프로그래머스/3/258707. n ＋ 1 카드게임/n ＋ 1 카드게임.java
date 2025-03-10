import java.util.*;

class Solution {
    public int solution(int coin, int[] cards) {
        int answer = 1;
        int n = cards.length;
        int c = n+1;
        int life = 0;
        int two_coin_life = 0;
        int one_coin_life = 0;
        Set<Integer> set = new HashSet<>();
        Set<Integer> no_coin = new HashSet<>();
        
        for(int i=0;i<n/3;i++){
            int now = cards[i];
            if(set.contains(c-now)){
                set.remove(c-now);
                life++;
            }else set.add(now);
        }
        for(int i=n/3;i<n;i++){
            int first = cards[i++];
            int second = cards[i];
            //life 충전
            if(set.contains(c-first)){
                set.remove(c-first);
                one_coin_life++;
            }else if(no_coin.contains(c-first)){
                no_coin.remove(c-first);
                two_coin_life++;
            }else no_coin.add(first);
                
            if(set.contains(c-second)){
                set.remove(c-second);
                one_coin_life++;
            }else if(no_coin.contains(c-second)){
                no_coin.remove(c-second);
                two_coin_life++;
            }else no_coin.add(second);
            
            //life 소모
            if(life>0) life--;
            else if(one_coin_life>0){
                if(coin>=1){
                    coin--;
                    one_coin_life--;
                }else break;
            }else if(two_coin_life>0){
                if(coin>=2){
                    coin -= 2;
                    two_coin_life--;
                }else break;
            }else break;
            // System.out.println(first+" "+second);
            // System.out.println("life "+life);
            // System.out.println("one "+one_coin_life);
            // System.out.println("two "+two_coin_life);
            // System.out.println();
                
            answer++;
        }
        return answer;
    }
}