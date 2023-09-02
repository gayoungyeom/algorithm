function solution(triangle) {
    const n = triangle.length;
    let d = Array.from(Array(n), () => Array(n).fill(0));
    
    d[0][0] = triangle[0][0];
    
    for(let i = 1; i < n; i++){
        for(let j = 0; j <= i; j++){
            d[i][j] = Math.max(d[i - 1][j - 1] || 0, d[i - 1][j]) + triangle[i][j];
        }
    }

    return Math.max(...d[n - 1]);
}
