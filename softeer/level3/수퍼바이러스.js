const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim();
const [k, p, n] = input.split(' ').map(Number);

const MOD = 1000000007;
function solution(k, p, n){
    const div = (x, y) => { //O(logN)을 위한 분할
        if(y === 1){
            return x;
        } else if(y % 2 === 0){
            const d = div(x, y / 2);
            return (d * d) % MOD;
        } else{
            const d = div(x, (y - 1) / 2);
            return (x * d * d) % MOD
        }
    }

    return (div(p, n * 10) * k) % MOD;
}

console.log(solution(k, p, n));
