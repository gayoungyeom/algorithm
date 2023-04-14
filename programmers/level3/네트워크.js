function solution(n, computers) {
    let graph = Array.from(Array(n), () => []);
    let visited = [...Array(n).fill(false)];
    
    for(let i = 0; i < computers.length; i++){
        for(let j = i + 1; j < computers[i].length; j++){
            if(computers[i][j]){
                graph[i].push(j);
                graph[j].push(i);
            }
        }
    }
    
    const dfs = (cur) => {
        visited[cur] = true;
        for(let i = 0; i < graph[cur].length; i++){
            if(!visited[graph[cur][i]]){
                dfs(graph[cur][i]);
            }
        }
    }

    const bfs = (cur) => {
        const q = [];
        q.push(cur);
        visited[cur] = true;
        
        while(q.length !== 0){
            const x = q.shift();
            for(let i = 0; i < graph[x].length; i++){
                const next = graph[x][i];
                if(!visited[next]){
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
    }
    
    let cnt = 0;
    for(let i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i); //or bfs(i);
            cnt++;
        }
    }
    return cnt;
}
