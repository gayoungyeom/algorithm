function solution(k, m, score) {
    const sorted = score.sort((a, b) => b - a);
    
    let p = 0;
    const n = ~~(score.length / m);
    
    for(let i = 1; i <= n; i++){
        p += sorted[m * i - 1];
    }
    
    return p * m;
}
