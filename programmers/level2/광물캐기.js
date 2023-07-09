function solution(picks, minerals) {
    //가지고 있는 곡괭이로 캘 수 있는 광물의 수만 남기기
    const canPicks = picks.reduce((a, b) => a + b) * 5;
    minerals = minerals.slice(0, canPicks);
    
    const order = []; //stone 곡괭이로 캤을 때 피로도
    for(let i = 0; i < minerals.length; i += 5){
        const five = minerals.slice(i, i + 5);
        let t = 0;
        for(let j = 0; j < five.length; j++){
            if(five[j] === 'diamond') t += 25;
            else if(five[j] === 'iron') t += 5;
            else t += 1;
        }
        order.push([i, t]);
    }
    order.sort((a, b) => b[1] - a[1]);
    
    let tired = 0;
    
    for(let i = 0; i < order.length; i++){
        const idx = order[i][0];
        let used;
        for(let j = idx; j < idx + 5 && j < minerals.length; j++){
            if(picks[0] > 0){
                tired += 1;
                used = 0;
            } else if(picks[1] > 0){
                if(minerals[j] === 'diamond'){
                    tired += 5;
                } else {
                    tired += 1;
                }
                used = 1;
            } else if(picks[2] > 0){
                if(minerals[j] === 'diamond'){
                    tired += 25;
                } else if(minerals[j] === 'iron'){
                    tired += 5;
                } else {
                    tired += 1;
                }
                used = 2;
            }
        }
        picks[used]--;
    }
    
    return tired;
}
