function solution(n) {
    const sqrt = Math.sqrt(n);
    return sqrt === ~~sqrt ? (sqrt + 1)**2 : -1;
}
