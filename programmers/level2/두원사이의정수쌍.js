function solution(r1, r2) {
    let dot = 0;
    
    for(let i = 1; i < r2; i++){
        const outer = Math.floor(Math.sqrt(r2**2 - i**2));
        const iy = Math.sqrt(r1**2 - i**2);
        const inner = iy === Math.floor(iy) ? iy - 1 : Math.floor(iy);
        dot += (outer - (r1 > i ? inner : 0));
    }
    
    return (dot + (r2 - r1 + 1)) * 4;    
}
