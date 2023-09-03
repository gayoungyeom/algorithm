function solution(operations) {
    const q = [];
    
    for(let i = 0; i < operations.length; i++){
        const [op, n] = operations[i].split(' ');
        
        if(op === 'I'){ //push
            q.push(n);
            q.sort((a, b) => b - a);
        } else { //pop
            if(q.length !== 0){
                if(n === '1'){ //최대
                    q.shift();
                } else{ //최소
                    q.pop();
                }
            }
        }
    }

    if(q.length === 0) return [0, 0];
    else return [+q[0], +q[q.length - 1]];
}
