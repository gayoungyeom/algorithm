
function solution(weights) {
    const MULTI = [[2, 3], [2, 4], [3, 4]];
    
    const m = new Map();
    for(let i = 0; i < weights.length; i++){
        m.set(weights[i], m.has(weights[i]) ? m.get(weights[i]) + 1 : 1);
    }    
    
    let result = 0;
    
    for(const [weight, count] of [...m]){
        result += ((count * (count - 1)) / 2);
        for(const [a, b] of MULTI){
            const tmp = (weight * b) / a;
            if(m.has(tmp)){
                result += (m.get(tmp) * count);
            }
        }
    }

    return result;
}
