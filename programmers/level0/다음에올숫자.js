//등비: a1 + r(n-1)
//등차: a1 * r^(n-1);
function solution(common) {
    const a1 = common[0];
    const d = common[1] - common[0];
    const r = common[1] / common[0];
    const n = common.length;
    
    if(a1 + d * (n - 1) === common[n-1])
        return a1 + d * n;
    
    if(a1 * Math.pow(r, n - 1) === common[n-1])
        return a1 * Math.pow(r, n);
}
