function solution(n, k) {
    var answer = [];
    function counting(n){
        let result = 1
        for(let i=n;i>0;i--){
            result *=i
        }
        return result
    }
    const visited = Array.from({length:n},_=>false)
    for(let i=1;i<=n;i++){
        for(let j=1;j<=n;j++){
            if(visited[j]) continue
            let count = counting(n-i)
            if(count<k){
                k -= count
                continue
            }else{
                answer.push(j)
                visited[j] = true
                break
            }
        }
    }
    return answer;
}