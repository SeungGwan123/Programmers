function solution(n, words) {
    var answer = [0,0];
    const set = new Set();
    let turn = 2
    set.add(words[0])
    for(let i=1;i<words.length;i++){
        const now = words[i]
        const last = words[i-1]
        if(last.at(-1)!==now[0] || set.has(now)){
            return [turn,Math.floor(i/n)+1]
        }else{
            set.add(now)
        }
        turn %= n
        turn++
    }

    return answer;
}