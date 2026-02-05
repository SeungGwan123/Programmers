function solution(n) {
    var answer = 0;
    let visited = Array.from({length:n},_=>{
        return Array.from({length:n},_=>0)
    })
    const visited_row = new Set()
    const visited_column = new Set()
    const set = new Set()
    function backtracking(row){
        if(row===n){
            answer++
            return
        }
        for(let j=0;j<n;j++){
            if(visited_column.has(j)) continue;
            if(visited[row][j]!==0) continue;
            
            tracking(row,j,true)
            visited_column.add(j)
            
            backtracking(row+1)
            
            visited_column.delete(j)
            tracking(row,j,false)
        }   
    }
    
    function tracking(x,y,attack){
        let track = attack === true ? 1 : -1
        const direction = [[1,1],[1,-1],[-1,1],[-1,-1]]
        
        visited[x][y] += track
        for(const dir of direction){
            let a = x
            let b = y
            while(a+dir[0]>=0&&a+dir[0]<n&&b+dir[1]>=0&&b+dir[1]<n){
                a += dir[0]
                b += dir[1]
                visited[a][b] += track
            }
        }
        return visited
    }
    
    backtracking(0,set,visited,[],visited_row,visited_column)
    //console.log(set)
    return answer;
}