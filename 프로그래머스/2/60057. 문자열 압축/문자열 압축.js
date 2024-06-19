function solution(s) {
    let answer = s.length;
    for(let i=1;i<=s.length/2;i++){
        let count = 0;
        let temp = '';
        for(let j=0;j<s.length;j++){
            let m=0;
            let n=j+i;
            let sub_count = i;
            while(true){
                if(s.charAt(j+m)!==s.charAt(n)) break;
                m++;
                n++;
                if(m===i) {
                    sub_count+=i;
                    m=0;
                }
            }
            if(sub_count>i){
                if(sub_count/i>=1000) count += i+4;
                else if(sub_count/i>=100) count += i+3;
                else if(sub_count/i>=10) count += i+2;
                else count += i+1;
                
                temp+=(sub_count/i);
                temp+=s.charAt(j);
                
            }else{
                if(j+i>=s.length) count+=(s.length-j);
                else count+=i;
                temp+=s.charAt(j);
            }
            j+=(sub_count-1);
        }
        answer = Math.min(answer,count);
        temp+=' '+count;
        //console.log(temp);
    }
    return answer;
}