function solution(n) {
    var answer = '';
    const one_two_four = ['1','2','4']

    while(n>0){
        let now = n % 3
        n = Math.floor(n/3)
        if(now===0){
            n--
            now = 3
        }
        answer = one_two_four[now-1] + answer
    }
    return answer;
}