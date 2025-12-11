function solution(plans) {
    var answer = [];
    plans = plans.map((p)=>{
        const time = p[1];
        const trans = parseInt(time.slice(0,2))*60+parseInt(time.slice(3,5))
        p[1] = trans
        p[2] = parseInt(p[2])
        return p
    })
    plans.sort((a,b)=>b[1]-a[1])
    const trash = [];
    while(plans.length>0){
        const now = plans.pop();
        if(plans.length===0) answer.push(now[0])
        else{
            const next = plans.pop();
            if(now[1]+now[2]<=next[1]){
                answer.push(now[0])
                let rest = next[1] - (now[1]+now[2])
                while(rest>0&&trash.length>0){
                    const now_trash = trash.pop();
                    if(rest>=now_trash[2]){
                        rest -= now_trash[2]
                        answer.push(now_trash[0])
                    }else{
                        now_trash[2] -= rest
                        trash.push(now_trash)
                        rest = 0
                    }
                }
            }else{
                now[2] = now[2] - ( next[1] - now[1] )
                trash.push(now)
            }
            plans.push(next)
        }
    }
    while(trash.length>0){
        const now = trash.pop();
        answer.push(now[0])
    }
    return answer;
}