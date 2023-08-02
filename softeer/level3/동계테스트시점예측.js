const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
let [nm, ...rest] = input;
const [n, m] = nm.split(' ').map(Number);
const arr = rest.map(v => v.split(' ').map(Number));

function solution(n, m, arr){
    const dx = [-1, 0, 1, 0];
    const dy = [0, 1, 0, -1];

    const bfs = (sx, sy) => {
        const q = [];
        let visited = Array.from(Array(n), () => Array(m).fill(false));

        arr[sx][sy] = 2;
        q.push([sx, sy]);
        visited[sx][sy] = true;
        
        while(q.length !== 0){
            const [x, y] = q.shift();

            for(let i = 0; i < 4; i++){
                const nx = x + dx[i];
                const ny = y + dy[i];
                
                if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                if(!visited[nx][ny] && arr[nx][ny] !== 1){
                    arr[nx][ny] = 2;
                    q.push([nx, ny]);
                    visited[nx][ny] = true;
                }
            }
        }
    }

    const melting = () => {
        const melts = [];
        for(let x = 0; x < n; x++){
            for(let y = 0; y < m; y++){
                if(arr[x][y] === 1){
                    let count = 0;
                    for(let i = 0; i < 4; i++){
                        const nx = x + dx[i];
                        const ny = y + dy[i];

                        if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                            continue;
                        
                        if(arr[nx][ny] === 2){
                            count++;
                        }
                    }
                    if(count >= 2){
                        melts.push([x, y]);
                    }
                }
            }
        }

        for(const melt of melts){
            const [x, y] = melt;
            arr[x][y] = 2;
        }
    }

    const checkMeltAll = () => {
        for(let i = 0; i < n; i++){
            for(let j = 0; j < m; j++){
                if(arr[i][j] === 1) return false;
            }
        }
        return true;
    }
    
    let time = 0;

    while(!checkMeltAll()){
        bfs(0, 0); //외부 공기 체크
        melting(); //접촉 부분 녹이기
        time++;
    }

    return time;
}

console.log(solution(n, m, arr));
