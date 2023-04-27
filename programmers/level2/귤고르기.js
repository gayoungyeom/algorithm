function solution(k, tangerine) {
    const typeCnt = new Map();
    for(const tg of tangerine){
        typeCnt.set(tg, typeCnt.has(tg) ? typeCnt.get(tg) + 1 : 1);
    }
    
    const cnt = [...typeCnt].map(v => v[1]);
    cnt.sort((a, b) => b - a);
    
    let sum = 0;
    let ans = 0;
    for(let i = 0; i < cnt.length; i++){
        sum += cnt[i];
        if(sum >= k){
            ans = i + 1;
            break;
        }
    }
    return ans;
}
