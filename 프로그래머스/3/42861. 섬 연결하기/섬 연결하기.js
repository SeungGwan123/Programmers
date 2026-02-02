function solution(n, costs) {
    var answer = 0;
    costs.sort((a,b)=>a[2]-b[2])
    const visited = Array.from({length:n},_=>false)
    const parent = Array.from({length:n},_=>0).map((e,index)=>index)
    function find(x){
        if(parent[x]===x){
            return x
        }else{
            return parent[x] = find(parent[x])
        }
    }
    function union(x,y){
        x = find(x)
        y = find(y)
        
        if(x<y) parent[x] = find(y)
        else parent[y] = find(x)
    }
    let count = 0;
    let cost_index = 0
    for(const cost of costs){
        const [a,b,c] = cost
        if(find(a)!==find(b)){
            union(a,b)
            if(!visited[a]) visited[a] = true;
            if(!visited[b]) visited[b] = true;
            answer+=c
        }
    }
    return answer;
}