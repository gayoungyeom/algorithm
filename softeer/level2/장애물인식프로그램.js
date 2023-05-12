const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let [n, ...arr] = input;
n = +n;
arr = arr.map(v => v.split('').map(Number));

//풀이
const dx = [-1, 0, 1, 0];
const dy = [0, -1, 0, 1];

function solution(n, arr) {
    let visited = Array.from(Array(n), () => Array(n).fill(false));

    const bfs = (sx, sy) => {
        let cnt = 1;

        const q = [];
        q.push([sx, sy]);
        visited[sx][sy] = true;

        while(q.length !== 0){
            const [x, y] = q.shift();

            for(let i = 0; i < 4; i++){
                const nx = x + dx[i];
                const ny = y + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;

                if(!visited[nx][ny] && arr[nx][ny]){
                    q.push([nx, ny]);
                    visited[nx][ny] = true;
                    cnt++;
                }
            }
        }

        return cnt;
    }

    const result = [];
    for(let i = 0; i < n; i++){
        for(let j = 0; j < n; j++){
            if(!visited[i][j] && arr[i][j]){
                result.push(bfs(i, j));
            }
        }
    }

    let ans = '';
    ans += `${result.length}\n`;
    ans += result.sort((a, b) => a - b).join('\n');
    return ans;
}

console.log(solution(n, arr));

