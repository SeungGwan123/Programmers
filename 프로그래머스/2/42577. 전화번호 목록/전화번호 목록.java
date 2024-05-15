import java.util.*;
class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        Arrays.sort(phone_book);
        for(int i=0;i<phone_book.length-1;i++){
            String now = phone_book[i];
            String temp = phone_book[i+1];
                int max_size = Math.min(now.length(),temp.length());
                String pre = temp.substring(0,max_size);
                //System.out.println(now+" "+pre);
                if(now.equals(pre)) {
                    answer = false;
                    break;
                }
            if(!answer) break;
        }
        return answer;
    }
}