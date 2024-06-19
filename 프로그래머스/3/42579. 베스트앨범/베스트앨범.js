function solution(genres, plays) {
    var answer = [];
    let total = [];
    let num = new Map();
    let total_gen = new Map();
    for(let i=0;i<genres.length;i++){
        let gen = genres[i];
        let play = plays[i];
        if(!num.has(gen)){
            num.set(gen,total.length);
            total.push([play,gen]);
            total_gen.set(gen,[[play,i]]);
        }else{
            total[num.get(gen)][0]+=play;
            let temp = total_gen.get(gen);
            temp.push([play,i]);
            total_gen.set(gen,temp);
        }
    }
    total.sort((a,b)=> b[0]-a[0]);
    for(let i=0;i<total.length;i++){
        let now = total[i][1];
        console.log(now);
        let music = total_gen.get(now);
        music.sort((a, b) => {
            if (b[0] === a[0]) {
                return a[1] - b[1];
            } else {
                return b[0] - a[0];
            }
        });
        for(let j=0;j<music.length&&j<2;j++){
            answer.push(music[j][1]);
        }
    }
    return answer;
}