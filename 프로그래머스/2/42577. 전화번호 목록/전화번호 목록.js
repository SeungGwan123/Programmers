function solution(phone_book) {
    var answer = true;
    phone_book.sort()
    
    for(let i=0;i<phone_book.length;i++){
        const now = phone_book[i]
        for(let j=i+1;j<phone_book.length;j++){
            let check = false
            let con = false
            const next = phone_book[j]
            for(let w=0;w<now.length;w++){
                if(w===0&&now[w]!==next[w]){
                    check = true;
                    break;
                }
                if(now[w]!==next[w]){
                    if(now[w]<next[w]) check = true
                    con = true
                    break;
                }
            }
            if(check) break;
            if(con) continue;
            return false
        }
    }
    
    return answer;
}