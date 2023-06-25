function solution(maps) {
    const n = maps.length; 
    const m = maps[0].length;
    
    let count = 0;
    
    const dx = [-1, 0, 1, 0];
    const dy = [0, -1, 0, 1];
    let visited = Array.from(Array(n), () => Array(m).fill(false));
    
    const dfs = (x, y) => {
        visited[x][y] = true;
        
        for(let i = 0; i < 4; i++){
            const nx = x + dx[i];
            const ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            
            if(!visited[nx][ny] && maps[nx][ny] !== 'X'){
                dfs(nx, ny);
                count += Number(maps[nx][ny]);
            }
        }
    }
    
    const result = [];
    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            if(!visited[i][j] && maps[i][j] !== 'X'){
                count = Number(maps[i][j]);
                dfs(i, j);
                result.push(count);
            }
        }
    }
        
    return result.length > 0 ? result.sort((a, b) => a - b) : [-1];
}
