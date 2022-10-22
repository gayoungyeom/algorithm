function solution(n) {
    const sqrt = Math.sqrt(n);
    return Number.isInteger(sqrt) ? 1 : 2;
}
