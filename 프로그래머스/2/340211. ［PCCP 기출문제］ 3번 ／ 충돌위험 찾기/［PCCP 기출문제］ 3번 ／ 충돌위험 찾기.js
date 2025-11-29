function solution(points, routes) {
    var answer = 0;
    const set = new Set();
    const duplicate_set = new Set();
    
    function visit(n,t){
        const log = `${n[0]},${n[1]},${t}`
        const visited = set.has(log)
        const counted = duplicate_set.has(log)
        if(visited&&!counted){
            answer++
            duplicate_set.add(log)
        }else set.add(log)
    }
    
    for(const route of routes){
        let time = 0;
        let now = [...points[route[0] - 1]]
        visit(now,time)
        for(let i=1;i<route.length;i++){
            let next = [...points[route[i]-1]]
            
            while(now[0]!==next[0]||now[1]!==next[1]){
                if(now[0]<next[0]){
                    now[0]++;
                }else if(now[0]>next[0]){
                    now[0]--;
                }else if(now[1]<next[1]){
                    now[1]++;
                }else if(now[1]>next[1]){
                    now[1]--;
                }
                time++
                visit(now,time)
            }
        }
    }
    return answer;
}