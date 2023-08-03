const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
let [hw, ...rest] = input;
const [h, w] = hw.split(' ').map(Number);
let pixels = rest.slice(0, h);
pixels = pixels.map(pixel => pixel.split(' ').map(Number));
const q = +rest.slice(h, h + 1)[0];
const operations = rest.slice(h + 1).map(operation => operation.split(' ').map(Number));

function solution(h, w, pixels, q, operations){
    const dx = [-1, 0, 1, 0];
    const dy = [0 ,-1, 0, 1];

    const bfs = (sx, sy, c) => {
        const q = [];
        let visited = Array.from(Array(h), () => Array(w).fill(false));
        const color = pixels[sx][sy];

        pixels[sx][sy] = c;
        q.push([sx, sy]);
        visited[sx][sy] = true;

        while(q.length !== 0){
            const [x, y] = q.shift();

            for(let i = 0; i < 4; i++){
                const nx = x + dx[i];
                const ny = y + dy[i];

                if(nx < 0 || nx >= h || ny < 0 || ny >= w)
                    continue;

                if(!visited[nx][ny] && pixels[nx][ny] === color){
                    pixels[nx][ny] = c;
                    q.push([nx, ny]);
                    visited[nx][ny] = true;
                }
            }
        }
    }

    for(const operation of operations){
        const [x, y, c] = operation;
        bfs(x - 1, y - 1, c);
    }
    
    return pixels.map(v => v.join(' ')).join('\n');
}

console.log(solution(h, w, pixels, q, operations));
