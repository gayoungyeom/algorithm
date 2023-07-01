function solution(expression) {
    const nums = expression.split(/[+|*|-]/g).map(Number);
    const ops = expression.split(/\d/g).filter(v => v);
    
    const orders = [...new Set(ops)];
    const n = orders.length;
    let visited = [...Array(n).fill(false)];
    
    //연산자 우선순위 정하기 (6!이므로 재귀 돌리지 않고, 바로 상수 처리해도 됨)
    const prior = [];
    const go = (tmp) => {
        if(tmp.length === n){
            prior.push([...tmp]);
            return;
        }
        
        for(let i = 0; i < n; i++){
            if(!visited[i]){
                visited[i] = true;    
                tmp.push(orders[i]);
                go(tmp);
                tmp.pop();            
                visited[i] = false;    
            }
        }
    }
    
    go([]);
    
    //우선순위에 맞게 수식 연산하기
    let result = 0;
    for(let i = 0; i < prior.length; i++){
        let tmpNums = [...nums];
        let tmpOps = [...ops];
        
        for(let j = 0; j < prior[i].length; j++){
            const op = prior[i][j];
            
            let idxLen = tmpOps.filter(v => v === op).length;
            while(idxLen--){
                const idx = tmpOps.indexOf(op);
                let cur = 0;

                if(op === '+'){
                    cur = tmpNums[idx] + tmpNums[idx + 1];
                } else if(op === '-'){
                    cur = tmpNums[idx] - tmpNums[idx + 1];
                } else if(op === '*'){
                    cur = tmpNums[idx] * tmpNums[idx + 1];
                }
                
                tmpNums.splice(idx, 2, cur);
                tmpOps.splice(idx, 1);
            }
        }
        
        result = Math.max(result, Math.abs(tmpNums[0]));
    }
    
    return result;
}
