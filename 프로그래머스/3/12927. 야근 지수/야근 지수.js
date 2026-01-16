function solution(n, works) {
    let answer = 0;
    works.sort((a,b)=>a-b);
    let min = 0
    let max = works.at(-1)
    let mid = Math.ceil((min+max)/2)
    while(min<max){
        let count = 0;
        for(const work of works){
            if(work>mid){
                count += (work - mid)
            }
        }
        if(count>=n) min = mid
        else max = mid-1
        mid = Math.ceil((min+max)/2)
    }
    let count = 0;
    for(const work of works){
        if(work>mid){
            count+=(work-mid)
        }
    }

    for(let i=works.length-1;i>=0;i--){
        if(count>n){
            answer+=Math.pow(mid+1,2)
            count--
        }else answer+=Math.pow(Math.min(works[i],min),2)
    }
    
    return answer;
}