function solution(number, limit, power) {
    var answer = 1;
    let weapon = [1];
    for(let i=2;i<=number;i++){
        let count = 2;
        for(let j=2;j*j<=i;j++){
            if(i%j===0) count+=2;
            if(j*j===i) count--;
        }
        //console.log(count);
        if(count>limit) answer+=power;
        else answer+=count;
    }
    
    return answer;
}