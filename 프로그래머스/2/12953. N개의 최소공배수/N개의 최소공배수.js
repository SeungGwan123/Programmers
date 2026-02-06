function solution(arr) {
    var answer = 1;
    const set = Array.from({length:arr.length},_=>{
        return Array.from({length:101},_=>0)
    })
    
    for(const [index,e] of arr.entries()){
        for(let i=2;arr[index]!==1&&i<=arr[index];i++){
            while(arr[index]/i===Math.floor(arr[index]/i)){
                arr[index] = arr[index]/i
                set[index][i]++
            }
        }
    }
    
    const result = Array.from({length:101},_=>0)
    
    for(const s of set){
        for(let i=0;i<s.length;i++){
            result[i] = Math.max(s[i],result[i])
        }
    }

    for(const [index,r] of result.entries()){
        if(r!==0) answer *= Math.pow(index,r)
    }
    
    return answer;
}