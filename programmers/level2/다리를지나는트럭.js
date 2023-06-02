//1. 모든 시간 count
const EMPTY = 0;
function solution(bridge_length, weight, truck_weights) {
    const startWeight = truck_weights[0];
    if(startWeight > weight) return 0;
    
    const q = [];
    q.push(startWeight);
    let curWeight = startWeight;
    let time = 1;
    let i = 1;
    
    while(q.length !== 0){
        if(q.length === bridge_length){
            const passed = q.shift();
            curWeight -= passed;
        }
        
        if(curWeight + truck_weights[i] <= weight){
            q.push(truck_weights[i]);
            curWeight += truck_weights[i];
            i++;
        } else {
            q.push(EMPTY);
        }
        
        time++;
        if(curWeight === 0) break;
    }
    
    return time;
}

//2. 효율성 (w/ time jump)
function solution(bridge_length, weight, truck_weights) {
    let time = 0;
    let curWeight = 0;
    
    const q = [];
    q.push([0, time]); //[무게, 다리를 지난 시간]
    
    while(q.length !== 0 || truck_weights.length !== 0){
        if(time === q[0][1]) curWeight -= q.shift()[0];
            
        if(curWeight + truck_weights[0] <= weight){
            curWeight += truck_weights[0];
            q.push([truck_weights.shift(), time + bridge_length]);
        } else{
            //다음 트럭이 올라오지 못하는 경우, 그 시간으로 점프
            if(q[0]) time = q[0][1] - 1;
        }
        
       time++;
    }
    
    return time;
}
