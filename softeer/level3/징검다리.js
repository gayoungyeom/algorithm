const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
let [n, arr] = input;
n = +n;
arr = arr.split(' ').map(Number);

function solution(n, arr){
    let d = [...Array(n).fill(1)];

    for(let i = 1; i < n; i++){
        let max = 0;
        for(let j = i - 1; j >= 0; j--){
            if(arr[i] > arr[j]){
                max = Math.max(max, d[j]);
            }
        }
        d[i] = max + 1;
    }
    
    return Math.max(...d);
}

console.log(solution(n, arr))
