function solution(park, routes) {
    var answer = [];
    let board = [];
    let start = [];
    let dir = {'N':[-1,0],'S':[1,0],'W':[0,-1],'E':[0,1]};
    const height = park.length;
    const width = park[0].length;
    park.forEach((row,r_index)=>{
        let rows = [];
        row.split('').forEach((columns,c_index)=>{
            if(columns==='S') start.push(r_index,c_index);
            rows.push(columns);
        })
        board.push(rows);
    })
    //console.log(board);
    routes.forEach(r=>{
        let now_route = r.split(' ');
        let loc = [start[0],start[1]];
        let check = true;
        now_route[1] = Number(now_route[1]);
        //console.log(start+" "+check);
        for(let i=0;i<now_route[1];i++){
            loc[0] += dir[now_route[0]][0];
            loc[1] += dir[now_route[0]][1];
            if(loc[0]<0||loc[0]>=height||loc[1]<0||loc[1]>=width) check = false;
            if(!check) break;
            if(board[loc[0]][loc[1]]==='X') check = false;
            if(!check) break;
        }
        if(check){
            start = loc;
            //console.log('hi');
        }
        //console.log(start+" "+check);
    })
    return start;
}