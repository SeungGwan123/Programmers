function solution(s) {
    var answer = '';
    s = s.split(" ").map((e)=>{
        e = e.toLowerCase()
        if(!e) return e
        return e[0].toUpperCase() + e.slice(1)
    }).join(" ")
    return s;
}   