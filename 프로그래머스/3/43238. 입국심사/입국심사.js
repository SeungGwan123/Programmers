function solution(n, times) {
    var answer = 0;
    
    let high = n * 1_000_000_000
    let low = 1
    let mid = Math.floor((high+low)/2)
    
    while(low<high){
        let test = 0
        for(const t of times){
            test += Math.floor(mid/t)
        }
        if(test>=n) high = mid
        else low = mid+1
        mid = Math.floor((high+low)/2)
    }
    answer = mid
    return answer;
}