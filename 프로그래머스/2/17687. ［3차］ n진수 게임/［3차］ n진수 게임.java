class Solution {
    public String parseNum(int num,int n){
        String result = "";
        while(num>0){
            int now = num%n;
            num /= n;
            if(now==10){
                result = "A" + result;
            }else if(now==11){
                result = "B" + result;
            }else if(now==12){
                result = "C" + result;
            }else if(now==13){
                result = "D" + result;
            }else if(now==14){
                result = "E" + result;
            }else if(now==15){
                result = "F" + result;
            }else{
                result = Integer.valueOf(now) + result;
            }
        }
        return result;
    }
    public String solution(int n, int t, int m, int p) {
        String answer = "";
        int num = 0;
        String str_num = "0";
        int str_count = 0;
        while(answer.length()<t){
            for(int i=0;i<m;i++){
                if(str_num.length()==str_count){
                    str_num = parseNum(++num,n);
                    str_count = 0;
                }
                if(i==p-1){
                    answer += str_num.charAt(str_count++);
                }else str_count++;
                //System.out.println(str_num);
            }
        }
        return answer;
    }
}