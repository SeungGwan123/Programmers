function solution(players, callings) {
    var answer = [];
    let run = new Map();
    for(let i=0;i<players.length;i++){
        run.set(players[i],i);
    }
    for(let i=0;i<callings.length;i++){
        let now = callings[i];
        let level = run.get(now);
        run.set(now,level-1);
        let front = players[level-1];
        run.set(front,run.get(front)+1);
        players[level-1] = now;
        players[level] = front;
    }
    return players;
}