function solution(n) {
    var answer = 0;
    let start = 1
    let end = 1
    let count = 0
    while(end<=n){
        count+=end
        if(count===n) answer++
        end++
        while(count>n){
            count-=start
            if(count===n) answer++
            start++
        }
    }
    while(count>=n){
        count-=start
        if(count===n) answer++
        start++
    }
    return answer;
}