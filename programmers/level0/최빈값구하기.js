//1. 배열 활용 (공간복잡도 무시)
const MAX_LIMIT = 10001;

function solution(array) {
    const freq = Array(MAX_LIMIT).fill(0);
    array.forEach(a => freq[a]++);
    
    const max = Math.max(...freq);
    const isOnly = freq.filter(f => f === max).length === 1 ? 1 : 0;
    
    return isOnly ? freq.indexOf(Math.max(...freq)) : -1; 
}

//2. Map 활용
function solution(array) {
    const counter = new Map();
    array.forEach(a => counter.has(a) ? counter.set(a, counter.get(a) + 1) : counter.set(a, 1));
    
    const sorted = [...counter].sort((a, b) => b[1] - a[1]);
    return sorted.length === 1 || sorted[0][1] !== sorted[1][1] ? sorted[0][0] : -1;
}

