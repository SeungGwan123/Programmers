function solution(n, cores) {
    var answer = 0;
    let high = 500_000_000
    let low = 0
    let mid = Math.floor((high+low)/2)
    let job_count = 0;
    while(low<high){
        job_count = 0;
        for(const core of cores){
            job_count+=(Math.floor(mid/core)+1)
        }
        if(job_count>=n){
            high = mid
        }else low = mid+1
        mid = Math.floor((high+low)/2)
    }
    job_count = 0;
    for (const c of cores) job_count += Math.floor(low / c) + 1;
    for(let i=cores.length-1;i>=0;i--){
            const core = cores[i]
            if(Math.floor(mid/core)===mid/core){
                if(job_count===n){
                    answer = i+1
                    break
                }
                job_count--
            }
        }
    return answer;
}