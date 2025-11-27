function solution(n, q, ans) {
    var answer = 0;
    function isEqualArray(a, b) {
  return JSON.stringify(a) === JSON.stringify(b);
}
    function bfs(array,start){
        if(start===n+1) return;
        for(let i=start;i<=n;i++){
            let check = false
            array.push(i);
            
            for(let j=0;j<q.length;j++){
                const result = array.filter(value => q[j].includes(value)).length;
                if(array.length===5&&result!==ans[j]){
                    check = true
                    break;
                }
                if((array.length-result)>(5-ans[j])){
                    check = true
                    break;
                }
                if(result>ans[j]){
                    check = true
                    break;
                }
            }

            if(check){
                array.pop();
            }else{
                if(array.length===5){
                    answer++;
                    array.pop();
                    continue;
                }
                bfs(array,i+1)
                array.pop();
            }
        }
    }
    bfs([],1)

    return answer;
}