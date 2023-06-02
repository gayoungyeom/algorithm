const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim();
const arr = input.split(' ').map(Number);

function solution(arr){
    const ascend = arr.slice().sort((a, b) => a - b);
    const descend = arr.slice().sort((a, b) => b - a);

    let isAscend = true;
    let isDescend = true;
    for(let i = 0; i < arr.length; i++){
        if(ascend[i] !== arr[i]){
            isAscend = false;
        }
        if(descend[i] !== arr[i]){
            isDescend = false;
        }
    }

    if(isAscend) return 'ascending';
    if(isDescend) return 'descending';
    return 'mixed';
}

console.log(solution(arr));
