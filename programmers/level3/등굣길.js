const MOD = 1000000007;

function solution(m, n, puddles) {
    let d = Array.from(Array(n), () => Array(m).fill(-1));
    
    for(const puddle of puddles){
        const [x, y] = puddle;
        d[y - 1][x - 1] = 0;
    }
    
    //초기화
    d[0][0] = 0;
    let sn = n, sm = m;
    
    for(let i = 1; i < n; i++){
        if(d[i][0] === 0) {
            sn = i + 1;
            break;
        }
        d[i][0] = 1;
    }
    for(let i = sn; i < n; i++){
        d[i][0] = 0;
    }
    
    for(let i = 1; i < m; i++) {
        if(d[0][i] === 0) {
            sm = i + 1;
            break;
        }
        d[0][i] = 1;
    }
    for(let i = sm; i < m; i++){
        d[0][i] = 0;
    }
    
    for(let i = 1; i < n; i++){
        for(let j = 1; j < m; j++){
            if(d[i][j] !== 0){
                d[i][j] = (d[i - 1][j] + d[i][j - 1]) % MOD;
            }
        }
    }

    return d[n - 1][m - 1] % MOD;
}
