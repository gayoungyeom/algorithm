const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
let [nk, arr] = input;
const [n, k] = nk.split(' ').map(Number);
arr = arr.split('');

function solution(n, k, arr){
    const robots = [];
    let d = [...Array(n).fill(0)]; //0: 집지 않은 부품, 1: 집은 부품, 2: 로봇

    for(let i = 0; i < n; i++){
        if(arr[i] === 'P'){
            robots.push(i);
            d[i] = 2;
        }
    }

    for(const robot of robots){
        let idx = robot - k;
        if(idx < 0) idx = 0;

        while(idx <= robot + k){
            if(d[idx] === 0){
                d[idx] = 1;
                break;
            } 
            idx++;
        }
    }

    return d.filter(v => v === 1).length;
}

console.log(solution(n, k, arr));
