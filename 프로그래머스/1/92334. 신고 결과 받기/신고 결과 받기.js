function solution(id_list, report, k) {
    var answer = Array(id_list.length).fill(0);
    const r = new Map(id_list.map((id,idx)=> [id,idx]));
    const s = [];
    id_list.forEach(()=>s.push(new Set()))
    report.forEach((p)=>{
        const[start,end] = p.split(" ")
        const num = r.get(end)
        s[num].add(start);
    })
    s.forEach((ss)=>{
        if(ss.size>=k){
            for(const sss of ss){
                answer[r.get(sss)]++
            }
        }
    })
    return answer;
}