const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let [t, ...nums] = input;
nums = nums.map(num => num.split(' ').map(Number));

let result = '';
for(let i = 1; i <= t; i++){
    const [a, b] = nums[i-1];
    result += `Case #${i}: ${a + b}\n`
}

console.log(result);
