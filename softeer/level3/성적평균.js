const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let [nk, arr, ...rest] = input;
const [n, k] = nk.split(' ').map(Number);
arr = arr.split(' ').map(Number);
const range = rest.map(v => v.split(' ').map(Number));

function solution(n, k, arr, range){
    let result = '';
    for(let i = 0; i < k; i++){
        let sum = 0;
        for(let j = range[i][0] - 1; j < range[i][1]; j++){
            sum += arr[j];
        }
        result += `${(sum / (range[i][1] - range[i][0] + 1)).toFixed(2)}\n`;
    }
    return result;
}

console.log(solution(n, k, arr, range));
