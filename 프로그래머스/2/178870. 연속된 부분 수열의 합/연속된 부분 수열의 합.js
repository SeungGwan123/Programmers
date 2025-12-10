function solution(sequence, k) {
    var ans_array = Infinity
    let answer = [];
    let start = 0;
    let end = 0;
    let result = 0;
    while(end<sequence.length){
        result += sequence[end];
        // console.log(result)
        // console.log(start+" "+end)
        // console.log()
        if(result===k){
            if(ans_array>end-start+1){
                ans_array = end-start+1
                answer = [start,end]
            }
        }
        while(result>k){
            result -= sequence[start++]
            if(result===k){
                if(ans_array>end-start+1){
                    ans_array = end-start+1
                    answer = [start,end]
                }
            }
        }
        end++
    }
    
    return answer;
}