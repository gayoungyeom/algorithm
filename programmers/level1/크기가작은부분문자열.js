function solution(t, p) {
    let ans = 0;
    const n = t.length - p.length + 1;
    
    for(let i = 0; i < n; i++){
        const cur = t.slice(i, i + p.length);
        if(Number(cur) <= Number(p)) ans++;
    }
    
    return ans;
}
