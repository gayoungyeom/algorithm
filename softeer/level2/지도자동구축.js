const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim();

const n = +input;

//풀이
function solution(n) {
    const d = [...Array(n+1)];
    d[0] = 2;

    for(let i = 1; i <= n; i++){
        d[i] = 2 * d[i - 1] - 1;
    }

    return d[n]**2;
}

console.log(solution(n));
