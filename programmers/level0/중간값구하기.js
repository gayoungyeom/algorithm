function solution(array) {
    const sorted = array.sort((a, b) => a - b);
    const midIdx = Math.floor(array.length / 2);
    return sorted[midIdx];
}
