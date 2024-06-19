function solution(s) {
    var answer = 1;
    let a = 1;
    let b = 0;
    let c = s.charAt(0);
    for(let i=1;i<s.length;i++){
        if(a===b){
            a=0;
            b=0;
            answer++;
            c=s.charAt(i);
        }
        if(s.charAt(i)===c) a++;
        else b++;
        //console.log('a = '+a+', b = '+b);
    }
    return answer;
}