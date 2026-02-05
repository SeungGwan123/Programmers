function solution(m, n, puddles) {
    var answer = 0;
    let board = Array.from({length:n},_=>{
        return Array.from({length:m},_=>0)
    })

    puddles.forEach(([x,y])=>{
        board[y-1][x-1] = -1
    })
    
    board[0][0] = 1
    for(let r_index=0;r_index<n;r_index++){
        for(let c_index=0;c_index<m;c_index++){
            let routes = 0
            if(board[r_index][c_index]===-1) continue
            if(r_index===0&&c_index===0) continue
            if(c_index>0 && board[r_index][c_index-1]>0){
                routes += board[r_index][c_index-1]%1_000_000_007
            }
            if(r_index>0 && board[r_index-1][c_index]>0){
                routes += board[r_index-1][c_index]%1_000_000_007
            }
            board[r_index][c_index] = routes%1_000_000_007
        }
    }
    
    answer = board[n-1][m-1]
    return answer;
}