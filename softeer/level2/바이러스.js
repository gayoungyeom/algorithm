const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim();
const [k, p, n] = input.split(' ').map(Number);

const MOD = BigInt(1000000007);
function solution(k, p, n){
    k = BigInt(k); p = BigInt(p);
    while(n--) k = (k * p) % MOD;
    return Number(k);
}

console.log(solution(k, p, n));
