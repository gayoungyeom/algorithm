const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
let [nm, ...rest] = input;
const [n, m] = nm.split(' ').map(Number);
let limits = [];
let checks = [];
for(let i = 0; i < n; i++) limits.push(rest[i]);
for(let i = n; i < n + m; i++) checks.push(rest[i]);
limits = limits.map(limit => limit.split(' ').map(Number));
checks = checks.map(check => check.split(' ').map(Number));

function solution(n, m, limits, checks){
    for(let i = 1; i < n; i++)
        limits[i][0] += limits[i - 1][0]; 
    for(let i = 1; i < m; i++)
        checks[i][0] += checks[i - 1][0];
    
    let maxSpeedDiff = 0;
    let i = 0; j = 0;
    while(i < n || j < m){
        const [limitLength, limitSpeed] = limits[i];
        const [checkLength, checkSpeed] = checks[j];

        if(limitSpeed <= checkSpeed)
            maxSpeedDiff = Math.max(maxSpeedDiff, checkSpeed - limitSpeed);

        if(limitLength < checkLength){
            i++;
        } else if(limitLength > checkLength){
            j++;
        } else{
            i++;
            j++;
        }
    }
   
    return maxSpeedDiff;
}

console.log(solution(n, m, limits, checks));
