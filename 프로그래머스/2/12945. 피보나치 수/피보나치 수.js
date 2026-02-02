function solution(n) {
    var answer = 0;
    const fibo = Array.from({length:n+1},_=>-1)
    fibo[0] = 0
    fibo[1] = 1
    for(let i=2;i<=n;i++){
        fibo[i] = fibo[i-1] + fibo[i-2]
        fibo[i] %= 1_234_567
    }
    answer = fibo[n]
    return answer;
}