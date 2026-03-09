function solution(m, n, board) {
    var answer = 0;
    const puzzle = Array.from({length:board[0].length},_=>{
        return Array.from({length:board.length},_=>-1)
    })
    for(let i=0;i<board.length;i++){
        for(let j=0;j<board[i].length;j++){
            puzzle[j][board.length-i-1] = board[i][j]
        }
    }
    function square(i,j,visited){
        let spot = puzzle[i][j]
        for(let a=0;a<2;a++){
            for(let b=0;b<2;b++){
                if(i+a>=puzzle.length||j+b>=puzzle[i].length) return 
                if(puzzle[i+a][j+b]===-1||puzzle[i+a][j+b]!==spot) return 
            }
        }
        for(let a=0;a<2;a++){
            for(let b=0;b<2;b++){
                visited[i+a][j+b] = true;
            }
        }
        return 
    }
    function remove(visited){
        let count = 0;
        for(let i=0;i<visited.length;i++){
            for(let j=0;j<visited[i].length;j++){
                if(visited[i][j]){
                    puzzle[i][j] = -1
                    count++
                }
            }
        }
        for(let i=0;i<visited.length;i++){
            const new_puzzle = []
            for(let j=0;j<visited[i].length;j++){
                if(puzzle[i][j]!==-1) new_puzzle.push(puzzle[i][j])
            }
            while(new_puzzle.length!==visited[i].length) new_puzzle.push(-1)
            puzzle[i] = new_puzzle
        }
        return count
    }
    let check = true;
    while(check){
        check = false
        const visited = Array.from({length:puzzle.length},_=>{
            return Array.from({length:puzzle[0].length},_=>false)
        })
        for(let i=0;i<puzzle.length;i++){
            for(let j=0;j<puzzle[i].length;j++){
                square(i,j,visited)
            }
        }
        const remove_spot = remove(visited)
        if(remove_spot>0){
            answer+=remove_spot
            check=true
        }
    }
    return answer;
}