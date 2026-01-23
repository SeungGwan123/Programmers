function solution(n) {
    var answer = 0;
    const number = []
    //if(n===2)return 3
    while(n>0){
        number.push(n%2)
        n = Math.floor(n/2)
    }
    let one_check = false
    let one_count = 0
    let zero_count = 0
    let index = -1;
    for(let i=0;i<number.length;i++){
        if(number[i]===1){
            one_check = true
            one_count++
        }else zero_count++
        if(one_check && number[i]===0){
            index = i
            break;
        }
    }
    if(index===-1&&zero_count===0){
        number.splice(number.length-1,0,0)
    }else if(index===-1){
        number[0] = 1
        for(let i=1;i<=zero_count+1 && i<number.length;i++) {
            number[i] = 0
        }
        number.push(1)
    }else{
        for(let i=0;i<number.length-1;i++){
            if(i<one_count-1) number[i] = 1
            else if(i<one_count-2+zero_count) number[i] = 0
            else{
                number[i] = 0
                number[i+1] = 1
                break;
            }
        }
    }
    let two = 1
    for(const num of number){
        answer += (two*num)
        two *= 2
    }
    // console.log(index)
    // console.log(zero_count)
    // console.log(one_count)
    // console.log(number)
    return answer;
}