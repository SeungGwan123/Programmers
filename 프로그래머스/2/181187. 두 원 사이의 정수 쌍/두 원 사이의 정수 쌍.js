function solution(r1, r2) {
    var answer = 0;
    
    function binary_search(i,r,boundary){
        let low = 0;
        let high = r;
        let mid = parseInt((low+high)/2)
        while(low<high){
            const dot = Math.sqrt(Math.pow(i,2) + Math.pow(mid,2))
            if(boundary){
                if(dot>r){
                    high = mid
                }else low = mid+1
            }else{
                if(dot>=r){
                    high = mid
                }else low = mid+1
            }
            mid = parseInt((high+low)/2)
        }
        return mid
    }

    let r1_count = 0;
    for(let i=1;i<r1;i++){
        r1_count += binary_search(i,r1,false)   
    }
    // 1_000_000 * 20 => 4ㅋ0_000_000
    let r2_count = 0;
    for(let i=1;i<=r2;i++){
        r2_count += binary_search(i,r2,true)
    }
    
    answer = r2_count - r1_count
    // console.log(r1_count)
    // console.log(r2_count)
    // console.log(answer)
    return answer*4;
}