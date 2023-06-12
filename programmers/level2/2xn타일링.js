const MOD = 1000000007;

function solution(n) {
    const d = [...Array(n + 1).fill(0)];
        
    d[1] = 1;
    d[2] = 2;
    for(let i = 3; i <= n; i++){
        d[i] = (d[i - 1] + d[i - 2]) % MOD;
    }  
    
    return d[n] % MOD;
}
