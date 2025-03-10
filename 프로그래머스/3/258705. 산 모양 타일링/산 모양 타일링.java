class Solution {
    public static int div = 10007;
    public int solution(int n, int[] tops) {
        int answer = 0;
        int[] tri = new int[n];
        int[] no_tri = new int[n];
        if(tops[0]==1){
            tri[0] = 3;
            no_tri[0] = 1;
        }else{
            tri[0] = 2;
            no_tri[0] = 1;
        }
        for(int i=1;i<n;i++){
            if(tops[i]==1){
                tri[i] = ((tri[i-1]*3)%div + (no_tri[i-1]*2)%div)%div;
                no_tri[i] = (tri[i-1] + no_tri[i-1])%div;
            }else{
                tri[i] = ((tri[i-1]*2)%div + no_tri[i-1])%div;
                no_tri[i] = (tri[i-1] + no_tri[i-1])%div;
            }
        }
        answer = (tri[n-1] + no_tri[n-1])%div;
        return answer;
    }
}