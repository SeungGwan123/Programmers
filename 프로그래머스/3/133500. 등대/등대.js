function solution(n, lighthouse) {
    var answer = 0;
    const light = new Map();
    const data = {}

    lighthouse.forEach((lh)=>{
        const first = lh[0];
        const second = lh[1];
          
        if(light.get(first)!==undefined){
            light.set(first,light.get(first)+1)
            data[first].push(second)
        }else{
            light.set(first,1);
            data[first] = [second]
        }
        if(light.get(second)!==undefined){
            light.set(second,light.get(second)+1)
            data[second].push(first)
        }else{
            light.set(second,1)
            data[second] = [first]
        }
    })
    
    const sortLight = new Map([...light].sort(([,v1],[,v2])=>v2-v1))
    const result = new Set();
   
    for(const [k, v] of sortLight){
        console.log(k+" "+v)
    }
//     sortLight.forEach((v,k)=>{
//         if(result.size===lighthouse.length+1) return;
//         //if(result.has(k)) return;
//         data[k].forEach((dv)=>{
//             result.add(dv);
            
//         })
//         result.add(k);
//         console.log("key : "+k)
//         console.log(result)
//         answer++;
        
//     })
    return answer;
}