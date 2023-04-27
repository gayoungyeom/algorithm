const DIV = 1234567;

function solution(n) {
    let d = [...Array(n + 1).fill(0)];
    
    for(let i = 1; i <= n; i++){
        if(i <= 2) d[i] = i;
        else d[i] = (d[i - 1] + d[i - 2]) % DIV;
    }
    
    return d[n];
}
