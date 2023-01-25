function solution(arr, divisor) {
    const filtered = arr.filter(a => a % divisor === 0).sort((a, b) => a - b);
    return filtered.length ? filtered : [-1];
}
