function solution(dice) {
    const n = dice.length;
    const diceA = [];
    
    const backtrack = (cur, tmp) => {
        if(tmp.length === n / 2){
            diceA.push([...tmp]);
            return;
        }
        
        for(let i = cur; i < n; i++){
            tmp.push(i);
            backtrack(i + 1, tmp);
            tmp.pop();
        }
    }
    
    //A가 가져갈 주사위 선택
    backtrack(0, []);
    
    const getSums = (arr) => {
        const sums = [];
        
        const cal = (cur, sum) => {
            if(cur === arr.length){
                sums.push(sum);
                return;
            }
            
            for(let i = 0; i < 6; i++){
                cal(cur + 1, sum + dice[arr[cur]][i]);
            }
        }
        
        cal(0, 0)
        
        return sums;
    }
    
    const wins = [];
    for(let i = 0; i < diceA.length; i++){
        //A, B가 가져간 주사위를 굴린 결과
        const sumA = getSums(diceA[i]);
        const sumB = getSums(diceA[diceA.length - i -1]);
        
        //결과 계산
        sumA.sort((a, b) => b - a);
        sumB.sort((a, b) => b - a);
        
        let win = 0, p = 0;
        for(let j = 0; j < sumA.length; j++){
            for(let k = p; k < sumB.length; k++){
                if(sumA[j] > sumB[k]){
                    win += sumB.length - k;
                    p = k;
                    break;
                } 
            }
        }
        wins.push(win);
    }

    let max = 0, maxIdx = 0;
    for(let i = 0; i < wins.length; i++){
        const win = wins[i];
     
        if(max < win){
            max = win;
            maxIdx = i;
        }
    }
    
    return diceA[maxIdx].map(v => v + 1).sort((a, b) => a - b);
}
