//1. filter
function solution(arr) {
    const min = Math.min(...arr);
    const filtered = arr.filter(a => a !== min);
    return filtered.length ? filtered : [-1];
}

//2. splice
function solution(arr) {
    arr.splice(arr.indexOf(Math.min(...arr)), 1);
    return arr.length ? arr : [-1];
}
