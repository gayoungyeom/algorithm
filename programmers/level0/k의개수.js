function solution(i, j, k) {
    const arr = [...Array(j + 1).keys()].slice(i); //i to j 
    return arr.join('').split('').filter(a => a === k.toString()).length;
}
