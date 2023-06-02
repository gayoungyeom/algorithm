const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
let [wn, ...arr] = input;
const [w, n] = wn.split(' ').map(Number);
arr = arr.map(v => v.split(' ').map(Number));

function solution(w, n, arr){
    arr.sort((a, b) => b[1] - a[1]);

    let curWeight = 0;
    let price = 0;
    let i = 0;

    while(curWeight < w){
        const [m, p] = arr[i++];
        const weight = Math.min(w - curWeight, m);
        curWeight += weight;
        price += (weight * p);
    }

    return price;
}

console.log(solution(w, n, arr));
