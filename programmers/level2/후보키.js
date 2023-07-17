function solution(relation) {
    let count = 0;
    
    const row = relation.length;
    const col = relation[0].length;
    
    const ck = new Set();
    const addProp = (cnt, cur, tmp) => {
        if(tmp.length === cnt){
            const set = new Set();
            for(let i = 0; i < row; i++){
                let candidate = '';
                for(let j = 0; j < cnt; j++){
                    candidate += relation[i][tmp[j]];
                }
                set.add(candidate);
            }
            if(set.size === row){
                const curCk = tmp.join('');
                let isCk = true;
                for(const value of ck.values()){
                    let cnt = 0;
                    for(let i = 0; i < value.length; i++){
                        if(curCk.includes(value[i])){
                            cnt++;
                        }
                    }
                    if(cnt === value.length){
                        isCk = false;
                        break;
                    }
                }
                if(isCk){
                    ck.add(curCk);
                    count++;
                }
            }
            return;
        }
        
        for(let i = cur; i < col; i++){
            if(!ck.has(i)){
                tmp.push(i);
                addProp(cnt, i + 1, tmp);
                tmp.pop();
            }
        }
    }
    
    for(let i = 1; i <= col; i++){
        for(let j = 0; j < col; j++){
            addProp(i, j, []);
        }
    }

    return count;
}
