function solution(today, terms, privacies) {
    var answer = [];
    let [year,month,days] = today.split('.').map(Number);
    let new_today = year*12+month;
    let plus = {};
    terms.forEach(t=>{
        let [name,num] = t.split(' ');
        plus[name] = Number(num);
    })
    privacies.forEach((p,index)=>{
        let [date,name] = p.split(' ');
        let [t_year,t_month,t_days] = date.split('.').map(Number);
        let p_day = t_year*12+t_month+plus[name];
        if(new_today>p_day) answer.push(index+1);
        else if(new_today===p_day){
            if(days>=t_days) answer.push(index+1);
        }
    })
    return answer;
}