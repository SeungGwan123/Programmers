function solution(prices) {
    var answer = Array.from({length:prices.length},_=>0);
    const con = new Map()
    
    for(let i=0;i<prices.length;i++){
        let end = -1
        //console.log(con)
        if(con.get(prices[i])<=i||con.get(prices[i])===undefined){
            for(let j=i+1;j<prices.length;j++){
                if(prices[j]<prices[i]){
                    end = j
                    break;
                }
            }
        }else end = con.get(prices[i])
        if(end===-1){
            answer[i] = prices.length - i - 1
        }else answer[i] = end - i
        
        con.set(prices[i],end)
    }
    return answer;
}