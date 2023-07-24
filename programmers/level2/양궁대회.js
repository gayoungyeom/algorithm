function solution(n, info) {
    let result = [-1];
    let maxDiff = 0;

    const backtrack = (cur, tmp) => {
        if(tmp.length === n){
            //라이언이 쏜 화살
            let ryanInfo = [...Array(11).fill(0)];
            for(const t of tmp){
                ryanInfo[t]++;
            }
            
            //점수 계산
            let apeach = 0;
            let ryan = 0;
            for(let i = 0; i < 11; i++){
                if(info[i] === 0 && ryanInfo[i] === 0) continue;
                
                if(info[i] < ryanInfo[i]) ryan += (10 - i);
                else apeach += (10 - i);
            }
            
            //낮은 점수를 더 많이 맞힌 경우 체크
            const check = () => {
                for(let i = 10; i >= 0; i--){
                    if(ryanInfo[i] > result[i]) return true;
                    else if(ryanInfo[i] < result[i]) return false;
                }
            }
                
            const diff = ryan - apeach;
            if(diff > 0 && maxDiff <= diff){
                if(maxDiff === diff && !check()) return;
                maxDiff = diff;
                result = [...ryanInfo];
            }
            return;
        }
        
        for(let i = cur; i < 11; i++){ //중복 순열
            tmp.push(i);
            backtrack(i, tmp);
            tmp.pop();
        }
    }
    
    backtrack(0, []);
    
    return result;
}
