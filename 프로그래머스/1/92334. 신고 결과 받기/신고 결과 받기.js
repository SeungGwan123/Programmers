function solution(id_list, report, k) {
    var answer = [];
    let notice = new Set();
    let check = new Map();
    let count = new Map();
    id_list.forEach(id=>{
        check.set(id,[]);
        count.set(id,0);
    })
    report.forEach(r=>{
        let temp = r.split(' ');
        if(!notice.has(temp.join())){
            notice.add(temp.join());
            count.set(temp[1],count.get(temp[1])+1);
            let email = check.get(temp[0]);
            email.push(temp[1]);
            check.set(temp[0],email);
        }
    })
    id_list.forEach(id=>{
        let temp = check.get(id);
        let temp_count = 0;
        temp.forEach(t=>{
            if(count.get(t)>=k) temp_count++;
        })
        answer.push(temp_count);
    })
    return answer;
}