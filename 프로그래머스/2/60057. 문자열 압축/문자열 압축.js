function solution(s) {
    let answer = s.length;
    for(let i=1;i<=s.length/2;i++){
        let words = [];
        for(let j=0;j<s.length;j+=i){
            words.push(s.slice(j,j+i));
        }
        //console.log(words[0].length);
        let now = 0;
        let count = 0;
        let num = 1;
        for(let j=1;j<words.length;j++){
            if(words[now]!==words[j]){
                if(num>=1000) count+=words[now].length+4;
                else if(num>=100) count+=words[now].length+3;
                else if(num>=10) count+=words[now].length+2;
                else if(num===1) count+=words[now].length;
                else count+=words[now].length+1;
                now = j;
                num=1;
            }else num++;
            if(j===words.length-1){
                if(num===1) count+=words[now].length;
                else{
                    if(num>=1000) count+=words[now].length+4;
                    else if(num>=100) count+=words[now].length+3;
                    else if(num>=10) count+=words[now].length+2;
                    else count+=words[now].length+1;
                }
            }
        }
        answer = Math.min(count,answer);
    }
    return answer;
}