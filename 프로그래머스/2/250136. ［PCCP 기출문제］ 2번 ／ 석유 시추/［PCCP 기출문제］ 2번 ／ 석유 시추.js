function solution(land) {
    var answer = 0;
    const n = land.length;
    const m = land[0].length;
    const dir = [[1,0],[-1,0],[0,1],[0,-1]]
    const value = new Map();
    const visited = Array.from({length:land.length},()=>{
        return Array.from({length:land[0].length},()=>false)
    })
    const oil_map = Array.from({length:m},()=>{
        return new Set();
    })
    let oil_num = 2;
    for(let i=0;i<n;i++){
        for(let j=0;j<m;j++){
            const oil = [[i,j]];
            let oil_amount = 0;
            while(oil.length>0){
                const [a,b] = oil.shift();
                if(land[a][b]===1&&!visited[a][b]){
                    land[a][b] = oil_num
                    visited[a][b] = true;
                    oil_map[b].add(oil_num)
                    oil_amount++;
                    for(let d=0;d<4;d++){
                        const x = a+dir[d][0];
                        const y = b+dir[d][1];
                        if(x<0||x>=n||y<0||y>=m) continue;
                        if(visited[x][y]||land[x][y]===0) continue;
                        oil.push([x,y])
                    }
                }
            }
            if(oil_amount>0){
                value[oil_num] = oil_amount
                oil_num++
            }
        }
    }
    for(let i=0;i<m;i++){
        let result = 0;
        for(const o of oil_map[i]){
            result+=value[o]
        }
        answer = Math.max(result,answer)
    }
    return answer;
}