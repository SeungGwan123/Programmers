function solution(genres, plays) {
    const map = new Map();
    const arr = []
    for(const [index,genre] of genres.entries()){
        arr.push([genre,plays[index],index])
        if(map.has(genre)){
            map.set(genre,map.get(genre)+plays[index])
        }else{
            map.set(genre,plays[index])
        }
    }
    arr.sort((a,b)=>{
        if(map.get(a[0])===map.get(b[0])){
            if(a[1]===b[1]) return a[2] - b[2]
            else return b[1] - a[1]
        }else return map.get(b[0]) - map.get(a[0])
    })
    const genre_count = new Map();
    const answer = arr.map((a)=>{
        if(genre_count.has(a[0])){
            const g_count = genre_count.get(a[0])
            if(g_count>1) return undefined
            genre_count.set(a[0],g_count+1)
            return a[2]
        }else{
            genre_count.set(a[0],1)
            return a[2]
        }
    }).filter(a=>a!==undefined)
    return answer
}