function solution(sticker) {
    var answer = 0;
    if(sticker.length===1) return sticker[0]
    
    let count = [0,0]
    let count_back = [0,0]
    
    count[0] = sticker[0]
    for(let i=1;i<sticker.length;i++){
        if(i<sticker.length-1){
            count = [count[1] + sticker[i],Math.max(count[0],count[1])]
        }
        count_back = [count_back[1] + sticker[i],Math.max(count_back[0],count_back[1])]
    }
    
    answer = Math.max(Math.max(count[0],count[1]),Math.max(count_back[0],count_back[1]))
    
    return answer;
}