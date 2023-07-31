const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
let [n, ...rest] = input;
n = +n;
const arr = rest.map(v => v.split(' ').map(Number));

function solution(n, arr){
    arr.sort((a, b) => a[1] === b[1] ? a[0] - b[0] : a[1] - b[1]);

    let result = 1;
    let cur = arr[0][1];

    for(let i = 1; i < n; i++){
        const [s, e] = arr[i];
        if(s >= cur){
            cur = e;
            result++;
        }
    }
    
    return result;
}

console.log(solution(n, arr));
