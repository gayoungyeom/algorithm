function solution(keymap, targets) {
    const alpha = {
        A: 0, B: 0, C: 0, D: 0, E: 0, F: 0, G: 0, 
        H: 0, I: 0, J: 0, K: 0, L: 0, M: 0, N: 0, 
        O: 0, P: 0, Q: 0, R: 0, S: 0, T: 0, U: 0, 
        V: 0, W: 0, X: 0, Y: 0, Z: 0,
    }
    
    for(let i = 0; i < keymap.length; i++){
        for(let j = 0; j < keymap[i].length; j++){
            const cur = keymap[i][j];
            if(alpha[cur] === 0) alpha[cur] = j + 1;
            else alpha[cur] = Math.min(alpha[cur], j + 1);
        }
    }
    
    const result = [];
    for(let i = 0; i < targets.length; i++){
        let sum = 0;
        let flag = true;
        for(let j = 0; j < targets[i].length; j++){
            if(alpha[targets[i][j]] === 0) {
                flag = false; 
                break;
            }           
            sum += alpha[targets[i][j]];
        }
        if(flag) result.push(sum);
        else result.push(-1);
    }
    
    return result;
}
