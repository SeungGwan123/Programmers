function solution(n, bans) {
    var answer = '';
    // 26개
    // 1 -> a
    // 10 -> aa
    // 30 -> 14
    // a -> 97
    // z -> 122
    
    //console.log(a.charCodeAt(0))
    //console.log(String.fromCharCode(122))
    bans.sort((a,b)=>{
        if(a.length===b.length) return a.localeCompare(b)
        else return a.length - b.length
    })
    for(const ban of bans){
        let ban_length = 0;
        for(let i=0;i<ban.length;i++){
            ban_length += (Math.pow(26,ban.length - i - 1)*(ban.charCodeAt(i) - 96))
        }
        if(ban_length<=n) n++
    }

    if(n>26){
        while(n>0){
            n--;
            const digit = n % 26;
            answer = String.fromCharCode(97 + digit) + answer;
            n = Math.floor(n / 26);
        }
    }else{
        answer = String.fromCharCode(n+96)
    }
    return answer;
}