//1. 초기
function solution(numlist, n) {
    const sorted = numlist.map(num => [Math.abs(num - n), num]).sort((a, b) => a[0] === b[0] ? b[1] - a[1] : a[0] - b[0]);
    return sorted.map(s => s[1]);
}

//2. 개선 (`|| b-a`를 추가해야 거리가 같을 때 큰 수가 앞에 옴)
function solution(numlist, n) {
    return numlist.sort((a, b) => Math.abs(a - n) - Math.abs(b - n) || b - a);
}
