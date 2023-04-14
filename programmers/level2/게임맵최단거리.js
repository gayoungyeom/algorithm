function solution(maps) {
    const dx = [-1, 0, 1, 0];
    const dy = [0, -1, 0, 1];
    
    const n = maps.length;
    const m = maps[0].length;
    let visited = Array.from(Array(n), () => Array(m).fill(false));
    
    const q = [];
    q.push([0, 0]);
    visited[0][0] = true;
    
    while(q.length !== 0){
        const [x, y] = q.shift();
        
        for(let i = 0; i < 4; i++){
            const nx = x + dx[i];
            const ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            if(!visited[nx][ny] && maps[nx][ny] === 1){
                maps[nx][ny] = maps[x][y] + 1;
                q.push([nx, ny]);
                visited[nx][ny] = true;
            }
        }
    }
    
    return maps[n-1][m-1] > 1 ? maps[n-1][m-1] : -1;
}
