const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
let [nm, arr, ...rest] = input;
const [n, m] = nm.split(' ').map(Number);
arr = arr.split(' ').map(Number);
const relations = rest.map(v => v.split(' ').map(Number));

function solution(n, m, arr, relations){
    let graph = Array.from(Array(n), () => []);

    for(const [a, b] of relations){
        graph[a - 1].push(b - 1);
        graph[b - 1].push(a - 1);
    }

    let count = 0;
    for(let i = 0; i < n; i++){
        let isBest = true;
        for(let j = 0; j < graph[i].length; j++){
            if(arr[i] <= arr[graph[i][j]]){
                isBest = false;
                break;
            }
        }
        if(isBest){
            count++;
        }
    }
    return count;
}

console.log(solution(n, m, arr, relations))
