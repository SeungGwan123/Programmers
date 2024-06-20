function solution(maps) {
    var answer = 1000000;
    let n = maps.length;
    let m = maps[0].length;
    let visited = Array.from({length:n},()=>Array(m).fill(1000000));
    let dir = [[1,0],[-1,0],[0,1],[0,-1]];
    let queue = [];
    queue.push([0,0,1]);
    //visited[0][0]=1;
    while(queue.length!==0){
        let now = queue.shift();
        let a = now[0];
        let b = now[1];
        //console.log(a+' '+b);
        let value = now[2];
        if(a===n-1&&b===m-1){
            answer = Math.min(answer,value);
            continue;
        }
        if(visited[a][b]<=value) continue;
        visited[a][b] = value;
        for(let d=0;d<4;d++){
            let x = a+dir[d][0];
            let y = b+dir[d][1];
            if(x<0||x>=n||y<0||y>=m) continue;
            if(visited[x][y]<=value+1||maps[x][y]===0) continue;
            queue.push([x,y,value+1]);
        }
    }
    if(answer===1000000) answer=-1;
    return answer;
}