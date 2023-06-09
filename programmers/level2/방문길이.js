function solution(dirs) {
    const DIR = { 'U': [-1, 0], 'D': [1, 0], 'R': [0, 1], 'L': [0, -1] };   
    
    const n = 11;
    const map = Array.from(Array(n), () => Array(n).fill(0));
    const visited = Array.from(Array(n), () => Array.from(Array(n), () => Array.from(Array(n), ()=> Array(n).fill(false)))); //(x, y) -> (nx, ny)
    
    let count = 0;
    let x = 5, y = 5;

    for(let i = 0; i < dirs.length; i++){
        const [dx, dy] = DIR[dirs[i]];
        const nx = x + dx;
        const ny = y + dy;
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        
        if(!visited[x][y][nx][ny] && !visited[nx][ny][x][y]){ //간선 방문 체크
            visited[x][y][nx][ny] = true;
            visited[nx][ny][x][y] = true;
            count++;
        }
        x = nx;
        y = ny;
    }
    
    return count;
}
