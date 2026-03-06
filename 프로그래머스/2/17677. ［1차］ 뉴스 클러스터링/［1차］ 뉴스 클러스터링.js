function solution(str1, str2) {
    var answer = 0;
    let set = 0
    // 65 90 97 122
    function check_english(word){
        if(word.charCodeAt(0)>=65&&word.charCodeAt(0)<=90||word.charCodeAt(0)>=97&&word.charCodeAt(0)<=122) return true
        else return false
    }
    const first = new Map();
    const first_check = [];
    const second_check = [];
    let second = 0
    for(let i=1;i<str1.length;i++){
        if(check_english(str1[i-1])&&check_english(str1[i])){
            let part = str1.slice(i-1,i+1).toLowerCase();
            //console.log(part)
            if(first.get(part)===undefined) first.set(part,1)
            else first.set(part,first.get(part)+1)
            set++
            first_check.push(part)
        }
    }
    for(let i=1;i<str2.length;i++){
        if(check_english(str2[i-1])&&check_english(str2[i])){
            const part = str2.slice(i-1,i+1).toLowerCase()
            //console.log(part)
            const first_word = first.get(part)
            if(first_word>0){
                first.set(part,first_word-1)
                second++
            }else set++
            second_check.push(part)
        }
    }
    if(first_check.length===0&&second_check.length===0) answer = 1
    else answer = second/set
    
    answer = parseInt(answer*65536)
    return answer;
}