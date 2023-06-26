function solution(k, d) {
    let ans = 0;
    
    for(let x = 0; x <= d; x += k){
        const y = Math.sqrt(d**2 - x**2);
        ans += Math.floor(y / k) + 1;
    }
    
    return ans;
}
