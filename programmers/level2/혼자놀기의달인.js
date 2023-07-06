function solution(cards) {
    const n = cards.length;
    let parent = [...Array(n + 1).fill(0)];
    for(let i = 1; i <= n; i++){
        parent[i] = i;
    }
    
    const findParent = (i) => {
        if(parent[cards[i - 1]] === parent[i]) return;
        
        parent[cards[i - 1]] = parent[i];
        findParent(cards[i - 1]);
    } 
    
    for(let i = 0; i < n; i++){
        findParent(i + 1);
    }
    
    //점수 계산
    const group = new Map();
    for(let i = 1; i <= n; i++){
        group.set(parent[i], group.has(parent[i]) ? group.get(parent[i]) + 1 : 1);
    }
    
    const count = [...group].sort((a, b) => b[1] - a[1]);
    return count.length > 1 ? count[0][1] * count[1][1] : 0;
    
}
