function solution(n, edge) {
    let graph = Array.from(Array(n + 1), () => []);
    
    for(const e of edge){
        const [u, v] = e;
        graph[u].push(v);
        graph[v].push(u);
    }
    
    let dist = [...Array(n + 1).fill(-1)];
    const q = [];
    dist[1] = 0;
    q.push(1);
    
    while(q.length !== 0){
        const cur = q.shift();
        for(let i = 0; i < graph[cur].length; i++){
            const next = graph[cur][i];

            if(dist[next] === -1){
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    
    const max = Math.max(...dist);
    return dist.filter(v => v === max).length;
}
