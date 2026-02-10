function solution(N, road, K) {
    var answer = 1;

    const board = Array.from({length:N},_=>{
        return Array.from({length:N},_=>Infinity)
    })

    const visited = Array.from({length:N},_=>false)
    visited[0] = true

    for(let [x,y,distance] of road){
        x--
        y--
        board[x][y] = Math.min(board[x][y],distance)
        board[y][x] = Math.min(board[y][x],distance)
    }
    
    const delivery = []
    for(let i=0;i<board[0].length;i++){
        if(board[0][i]===Infinity || visited[i]) continue
        if(board[0][i]>K) continue
        delivery.push([board[0][i],i])        
    }
    delivery.sort((a,b)=>b[0]-a[0])
    
    while(delivery.length>0){
        const [cost,end] = delivery.pop()
        if(cost>K||visited[end]) continue
        visited[end] = true
        
        answer++
        for(let i=0;i<board[end].length;i++){
            if(board[end][i]===Infinity || visited[i]) continue
            if(board[end][i]+cost>K) continue
            delivery.push([board[end][i]+cost,i]) 
        }
        delivery.sort((a,b)=>b[0]-a[0])
    }
    
    return answer;
}