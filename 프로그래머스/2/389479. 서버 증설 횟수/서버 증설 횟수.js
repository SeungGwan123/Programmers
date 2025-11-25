function solution(players, m, k) {
    var answer = 0;
    const server = Array.from({length:24},()=>0)
    function server_create(index){
        for(let i=index;i<24&&i<index+k;i++){
            server[i] += m
        }
        answer++;
    }
    for(let i=0;i<24;i++){
        while(players[i]>=server[i]+m) server_create(i)
    }

    return answer;
}
