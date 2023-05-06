function solution(n, left, right) {
    let arr = [];
    
    for(let x = left; x <= right; x++){
        const i = ~~(x / n);
        const j = x - (n * i);
        arr.push(Math.max(i, j) + 1);
    }

    return arr; 
}
