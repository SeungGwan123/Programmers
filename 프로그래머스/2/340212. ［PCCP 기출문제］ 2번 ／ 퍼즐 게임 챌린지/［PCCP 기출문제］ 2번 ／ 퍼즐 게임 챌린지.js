function solution(diffs, times, limit) {
    var answer = 0;
    let low = 1;
    let high = 100001;
    const easy = times
    while(low<high){
        let mid = parseInt((low+high)/2);
        let time = 0;
        for(let i=0;i<diffs.length;i++){
            const level = diffs[i];
            const now_time = times[i];
            const pre_time = times[i-1];
            if(level<=mid) time+=now_time;
            else time+=((level-mid)*(now_time+pre_time)+now_time);
        }
        if(time<=limit){
            answer = mid
            high = mid
        }else{
            low = mid+1
        }
    }
    return answer;
}