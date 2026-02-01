function solution(s) {
    var answer = '';
    s = s.split(" ")
    s = s.map((e)=>parseInt(e)).sort((a,b)=>a-b)
    console.log(s)
    answer = s[0] + " " + s[s.length-1]
    return answer;
}