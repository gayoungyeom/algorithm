function solution(maps) {
    const n = maps.length;
    const m = maps[0].length;
    
    let start, lever, exit;
    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            if(maps[i][j] === 'S') start = [i, j];
            if(maps[i][j] === 'L') lever = [i, j];
            if(maps[i][j] === 'E') exit = [i, j];
        }
    }
    
    const dx = [-1, 0, 1, 0];
    const dy = [0, -1, 0, 1];
    
    const dijkstra = (sx, sy) => {
        const d = Array.from(Array(n), () => Array(m).fill(Infinity));
        const visited = Array.from(Array(n), () => Array(m).fill(false)); 
        
        const q = [[sx, sy]];
        d[sx][sy] = 0;
        visited[sx][sy] = true;
        
        while(q.length !== 0){
            const [x, y] = q.shift();
            
            for(let i = 0; i < 4; i++){
                const nx = x + dx[i];
                const ny = y + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                if(!visited[nx][ny] && maps[nx][ny] !== 'X'){
                    q.push([nx, ny]);
                    d[nx][ny] = Math.min(d[nx][ny], d[x][y] + 1);
                    visited[nx][ny] = true;
                }
            }
        }
        
        return d;
    }
    
    const mv1 = dijkstra(start[0], start[1]);
    const mv2 = dijkstra(lever[0], lever[1]);
    const cnt1 = mv1[lever[0]][lever[1]];
    if(cnt1 === Infinity) return -1;
    const cnt2 = mv2[exit[0]][exit[1]];
    if(cnt2 === Infinity) return -1;
    
    return cnt1 + cnt2;
}
