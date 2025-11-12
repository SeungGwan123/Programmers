function solution(schedules, timelogs, startday) {
    var answer = 0;
    const set = new Set();
    schedules = change_time(schedules);
    startday--;
    //console.log(schedules)
    for(let i=0;i<timelogs[0].length;i++){
        startday++;
        if(startday===6 || startday===7) {
            startday = startday % 7
            continue;
        }
        for(let j=0;j<timelogs.length;j++){
            if(set.has(j)) continue;
            let attend = timelogs[j][i];
            if(schedules[j]<attend) {
                set.add(j);
                continue;
            }
            //if(i===timelogs[0].length-1) answer++;
        }
    }
    answer = schedules.length - set.size
    return answer;
}
function change_time(time){
    return time.map((t)=>{
        return transfer_clock(t+10);
    })
}
function transfer_clock(time){
    let t = time%100
    if(t>=60){
        time = time - 60;
        time = time + 100;
    }
    return time
}