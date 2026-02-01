function solution(jobs) {
    var answer = 0;
    jobs.sort((a,b)=>a[0]-b[0])
    
    const waiting = [];
    let job_index = 0;
    let now = 0;
    
    while(job_index<jobs.length || waiting.length>0){
        if(waiting.length===0){
            let time = jobs[job_index][0]
            while(job_index<jobs.length&&jobs[job_index][0]===time){
                waiting.push(jobs[job_index])
                job_index++
            }
        }
        const job = waiting.pop()
        
        now = Math.max(now,job[0]) + job[1]
        answer += now - job[0]

        while(job_index < jobs.length && now >= jobs[job_index][0]){
            waiting.push(jobs[job_index])
            job_index++
        }
        waiting.sort((a,b)=>{
            if(a[1]===b[1]) return b[0] - a[0]
            else return b[1] - a[1]
        })
    }
    
    return Math.floor(answer/jobs.length);
}