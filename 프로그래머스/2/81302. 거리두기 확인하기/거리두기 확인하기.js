function direction(place,i,j){
    const dir = [[1,0],[-1,0],[0,1],[0,-1]]
    for(let d=0;d<4;d++){
        let a = i + dir[d][0];
        let b = j + dir[d][1];
        if(a<0||b<0||a>=5||b>=5) continue;
        if(place[a][b]==='X') continue;
        if(place[a][b]==='P') return true;
        for(let dd=0;dd<4;dd++){
            let aa = a + dir[dd][0];
            let bb = b + dir[dd][1];
            if(aa<0||bb<0||aa>=5||bb>=5) continue;
            if(place[aa][bb]==='X'||(aa===i&&bb===j)) continue;
            if(place[aa][bb]==='P') return true;
        }
    }
}

function solution(places) {
    var answer = [];
    
    places.forEach((place)=>{
        let result = 1;
        place.forEach((p,i)=>{
            for(let j=0;j<p.length;j++){
                if(p[j]==='P'){
                    if(direction(place,i,j)){
                        result = 0;
                    }
                }
            }
        })
        answer.push(result)
    })
    return answer;
}