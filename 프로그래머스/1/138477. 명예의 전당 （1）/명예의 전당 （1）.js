function solution(k, score) {
    var answer = [];
    let honor = [];
    score.forEach(s=>{
        honor.push(s);
        honor.sort((a,b)=>b-a);
        if(honor.length>k) answer.push(honor[k-1]);
        else answer.push(honor[honor.length-1]);
    })
    return answer;
}