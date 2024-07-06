function solution(wallpaper) {
    let min_x=wallpaper.length,min_y=wallpaper[0].length,max_x=0,max_y=0;
    wallpaper.forEach((row,r_index)=>{
        row.split('').forEach((columns,c_index)=>{
            if(columns==='#'){
                min_x = Math.min(min_x,r_index);
                min_y = Math.min(min_y,c_index);
                max_x = Math.max(max_x,r_index+1);
                max_y = Math.max(max_y,c_index+1);
            }
        })
    })
    let answer = [min_x,min_y,max_x,max_y];
    return answer;
}