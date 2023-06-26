function solution(n, k) {
    let fact = [...Array(n + 1).fill(1)];
    for(let i = 1; i <= n; i++){
        fact[i] = fact[i - 1] * i;
    }
    
    const arr = [...Array(n + 1).keys()].slice(1);
    const result = [];
    let cur = n;
    
    k--;
    
    while(result.length !== n){
        const turn = fact[--cur];
        const idx = ~~(k / turn);
        k %= turn;
        
        result.push(arr[idx]);
        arr.splice(idx, 1);
    }
    
    return result;
}


