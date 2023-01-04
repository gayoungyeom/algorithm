//1. 순위 배열 생성해 업데이트하기
function solution(emergency) {
    const order = Array(emergency.length).fill(1);
    emergency.forEach((cur, idx) => emergency.forEach(e => cur < e && order[idx]++));
    return order;
}

//2. 정렬된 배열과 비교해 인덱스 취하기
function solution(emergency) {
    const sorted = [...emergency].sort((a, b) => b - a);
    return emergency.map(e => sorted.indexOf(e) + 1);
}
