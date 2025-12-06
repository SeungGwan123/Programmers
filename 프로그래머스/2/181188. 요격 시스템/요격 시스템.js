function solution(targets) {
    var answer = 0;
    targets = targets.sort((a,b)=>{
        if(a[1]===b[1]) return a[0] - b[0]
        else return a[1] - b[1]
    })
    
    let missile = 0;
    for(const target of targets){
        const [a,b] = target
        if(a<missile) continue;
        missile = b;
        answer++
    }

    return answer;
}