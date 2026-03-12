function solution(files) {
    var answer = [];
    const file = [];
    //48 57
    function cut(word){
        let head = ''
        let number = ''
        let tail = ''
        let number_start = false
        let number_end = false
        for(let i=0;i<word.length;i++){
            if(word.charCodeAt(i)>=48&&word.charCodeAt(i)<=57){
                if(!number_start) number_start = true
                number+=word[i]
                if(number.length===5){
                    tail = word.slice(i+1)
                    break;    
                }
                continue
            }
            if(number_start){
                tail = word.slice(i)
                break;
            }
            else head += word[i]
        }
        return [head.toLowerCase(),parseInt(number),tail,word]
    }
    
    
    for(let i=0;i<files.length;i++){
        file.push(cut(files[i]))
    }
    
    file.sort((a,b)=>{
        if(a[0]===b[0]) return a[1] - b[1]
        else return a[0].localeCompare(b[0])
    })
    //console.log(file)
    for(const f of file){
        answer.push(f[3])
    }
    
    return answer;
}