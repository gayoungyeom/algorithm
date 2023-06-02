const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim();
const [k, p, n] = input.split(' ').map(Number);

const MOD = 1000000007;
function solution(k, p, n){
    while(n--) k = (k * p) % MOD;
    return k;
}

console.log(solution(k, p, n));
