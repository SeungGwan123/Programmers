import java.util.*;

class Solution {
    public long StringToInt(String word){
        long result = 0;
        for(int i=word.length()-1;i>=0;i--){
            result += Math.pow(26,(word.length()-1)-i)*(long)(word.charAt(i)-96);
        }
        return result;
    }
    public String solution(long n, String[] bans) {
        String answer = "";
        TreeSet<Long> set = new TreeSet<>();
        for(int i=0;i<bans.length;i++){
            set.add(StringToInt(bans[i]));
        }
        
        if(set.size()>0){
            Long search = set.first();
            while(search<=n){
                n++;
                search = set.higher(search);
                if(search==null) break;
            }
        }
        int j = 0;
        while(n>0){
            long num = n%26;
            n = n/26;
            if(num==0) {
                answer = 'z' + answer;
                n--;
            }
            else answer = (char)(num+96) + answer;
        }
        return answer;
    }
}