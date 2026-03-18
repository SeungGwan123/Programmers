function solution(bridge_length, weight, truck_weights) {
    var answer = 0;
    let w = 0;
    const bridge = [];
    for(let i=0;i<truck_weights.length;i++){
        const now = truck_weights[i]
        while(w+now>weight){
            const [first_truck,time] = bridge.shift();
            answer = Math.max(answer,time+bridge_length)
            w-=first_truck
        }
        bridge.push([now,answer])
        w+=now
        answer++
    }
    if(bridge.length>0){
        answer = Math.max(answer,bridge[bridge.length-1][1]+bridge_length+1)
    }
    return answer;
}