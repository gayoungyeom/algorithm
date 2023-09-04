function solution(n, results) {
    let graph = Array.from(Array(n + 1), () => Array(n + 1).fill(0)); //win: 1, lose: -1
    
    for(const result of results){
        const [u, v] = result;
        graph[u][v] = 1; //u가 v를 이김
        graph[v][u] = -1; //u가 v에게 짐
    }
    
    for(let k = 1; k <= n; k++){
        for(let i = 1; i <= n; i++){
            for(let j = 1; j <= n; j++){
                if(graph[i][k] === 1 && graph[k][j] === 1) graph[i][j] = 1;
                if(graph[i][k] === -1 && graph[k][j] === -1) graph[i][j] = -1;
            }
        }
    }
    
    let result = 0;
    
    for(let i = 1; i <= n; i++){
        let cnt = 0;
        for(let j = 1; j <= n; j++){
            if(graph[i][j] === 0) cnt++;
        }
        if(cnt === 1) result++;
    }
 
    return result;
}
