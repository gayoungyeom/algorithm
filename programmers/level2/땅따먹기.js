function solution(land) {
    const n = land.length; //행
    const d = Array.from(Array(n), () => Array(4).fill(0));
    
    for(let i = 0; i < 4; i++) d[0][i] = land[0][i];
    
    for(let i = 1; i < n; i++){
        d[i][0] += land[i][0] + Math.max(d[i-1][1], d[i-1][2], d[i-1][3]);
        d[i][1] += land[i][1] + Math.max(d[i-1][0], d[i-1][2], d[i-1][3]);
        d[i][2] += land[i][2] + Math.max(d[i-1][0], d[i-1][1], d[i-1][3]);
        d[i][3] += land[i][3] + Math.max(d[i-1][0], d[i-1][1], d[i-1][2]);
    }
    
    return Math.max(...d[n-1]);
}
