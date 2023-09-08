function solution(n, costs) {
    let parent = [...Array(n).fill(0)];
    
    const findParent = (x) => {
        if(parent[x] === x) return parent[x];
        return parent[x] = findParent(parent[x]);
    }
    
    const unionParent = (a, b) => {
        a = findParent(a);
        b = findParent(b);
        if(a < b) parent[b] = a;
        else parent[a] = b;
    }
    
    for(let i = 0; i < n; i++){
        parent[i] = i;
    }
    
    //비용 기준 오름차순 정렬
    costs.sort((a, b) => a[2] - b[2]);
    
    let result = 0;
    
    for(const cost of costs){
        const [u, v, c] = cost;
        if(findParent(u) !== findParent(v)){ //연결되어 있지 않는 경우
            unionParent(u, v);
            result += c;
        }
    }
    
    return result;
}
