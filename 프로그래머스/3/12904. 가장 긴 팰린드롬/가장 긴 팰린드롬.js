function solution(s)
{
    var answer = 1;
    s = s.split("")
    for(let i=0;i<s.length;i++){
        let left = i-1;
        let right = i+1;
        let count = 0;
        while(left>=0&&right<s.length){
            //console.log(s[left]+" "+s[right])
            if(s[left]===s[right]){
                left--;
                right++;
                count++;
            }else break;
        }
        //console.log()
        answer = Math.max(answer,count*2+1)
        left = i;
        right = i+1;
        count = 0
        while(left>=0&&right<s.length){
            //console.log(s[left]+" "+s[right])
            if(s[left]===s[right]){
                left--;
                right++;
                count++;
            }else break;
        }
        answer = Math.max(answer,count*2)
    }
    
    return answer;
}