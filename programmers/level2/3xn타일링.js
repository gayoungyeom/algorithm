//d[i] = 3 * d[n - 2] + (2 * (d[n-4] + d[n-6] + ... + d[0]))
function solution(n) {
    const MOD = 1000000007;
    let d = [...Array(n + 1).fill(0)];
    
    d[0] = 1;
    d[2] = 3;
    for(let i = 4; i <= n; i += 2){
        for(let j = 4; j <= i; j += 2){ //짝수개일 때 경우의 수 2개씩 추가
            d[i] += 2 * d[i - j];
            d[i] %= MOD;
        }
        d[i] += (3 * d[i - 2]);
        d[i] %= MOD;
    }
    
    return d[n];
}
