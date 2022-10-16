function solution(n, k) {
    const service = ~~(n / 10);
    const cost = 12000 * n + 2000 * (k - service);
    return cost;
}
