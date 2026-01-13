function solution(sequence) {
    var answer = 0;
    const max_seq = [];
    for(const [index,seq] of sequence.entries()){
        const last_seq = max_seq.at(-1)
        if(last_seq===undefined){
            max_seq.push([[seq,true],[-seq,false]])
        }else{
            const positive = seq
            const negative = -seq
            max_seq.push([])
            // console.log(positive)
            // console.log(negative)
            // console.log(new_seq)
            // console.log()
            max_seq[index].push([Math.max(positive,max_seq[index-1][1][0]+positive),true])
            max_seq[index].push([Math.max(negative,max_seq[index-1][0][0]+negative),false])
        }
    }
    console.log(max_seq)
    for(const m of max_seq){
        answer = Math.max(Math.max(m[0][0],m[1][0]),answer)
    }
    return answer;
}