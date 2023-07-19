function solution(n) {
    let cnt = 0;
    const queen = [];
    
    const check = (x, y) => {
        for(let i = 0; i < x; i++){
            //아래
            if(queen[i] === y) return false;
            
            //대각선
            const gap = x - i;
            if(queen[i] + gap === y) return false;
            if(queen[i] - gap === y) return false;
        }
        return true;
    }
    
    const backtrack = (x) => {
        if(x === n){
            cnt++;
            return;
        }
        
        for(let y = 0; y < n; y++){
            if(check(x, y)){
                queen[x] = y;
                backtrack(x + 1); //다음 줄로 이동
            }
        }
    }
    
    backtrack(0);
    
    return cnt;
}
