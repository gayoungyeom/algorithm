const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let [t, ...arr] = input;
t = +t;
arr = arr.map(v => v.split(' '));

const EMPTY = [0, 0, 0, 0, 0, 0, 0];
const NUMBERS = {
    0: [1, 1, 1, 0, 1, 1, 1],
    1: [0, 0, 1, 0, 1, 0, 0],
    2: [0, 1, 1, 1, 0, 1, 1],
    3: [0, 1, 1, 1, 1, 1, 0],
    4: [1 ,0, 1, 1, 1, 0, 0],
    5: [1, 1, 0, 1, 1, 1, 0],
    6: [1, 1, 0, 1, 1, 1, 1],
    7: [1, 1, 1, 0, 1, 0, 0],
    8: [1, 1, 1, 1, 1, 1, 1],
    9: [1, 1, 1, 1, 1, 1, 0],
    '-': EMPTY,
};

let result = '';

for(let i = 0;  i < t; i++){
    let [a, b] = arr[i];
    a = a.padStart(5, '-');
    b = b.padStart(5, '-');
    
    let cnt = 0;
    for(let j = 0; j < 5; j++){
        for(let k = 0; k < 7; k++){
            if(NUMBERS[a[j]][k] !== NUMBERS[b[j]][k]){
                cnt++;
            }
        }
    }
    result += `${cnt}\n`;
}

console.log(result);
