function solution(A,B){
    var answer = 0;

    A.sort((a,b)=>a-b)
    B.sort((a,b)=>b-a)
    
    for(const [index,a] of A.entries()){
        answer+=a*B[index]
    }

    return answer;
}