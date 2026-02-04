function solution(N, number) {
    var answer = -1;
    const num = Array.from({length:9},_=>0).map((e,index)=>{
        return Number(String(N).repeat(index))
    })
    
    const set = new Set();
    set.add(N)
    
    const dp = Array.from({length:9},_=>[])
    dp[1].push(N)
    let check = false
    if(N===number) return 1
    
    for(let i=2;i<9;i++){
        dp[i].push(num[i])
        set.add(num[i])
        if(num[i]===number){
            answer = i;
            break;
        }
        for(let j=1;j<i;j++){
            dp[j].forEach((a,index)=>{
                dp[i-j].forEach((b,index)=>{
                    const plus = a+b
                    const minus = Math.max(a,b) - Math.min(a,b)
                    const divide = Math.max(a,b) / Math.min(a,b)
                    const remain = Math.max(a,b) * Math.min(a,b)
                    if(plus===number || minus===number || divide===number || remain===number){
                        answer = i
                        check = true;
                    }
                    
                    if(!set.has(plus)){
                        dp[i].push(plus)
                        set.add(plus)
                    }
                    if(!set.has(minus)){
                        dp[i].push(minus)
                        set.add(minus)
                    }
                    if(!set.has(divide)){
                        dp[i].push(divide)
                        set.add(divide)
                    }
                    if(!set.has(remain)){
                        dp[i].push(remain)
                        set.add(remain)
                    }
                })
            })
            if(check) break;
        }
        if(check) break;
    }
    //console.log(dp[7].slice(40))
    return answer;
}