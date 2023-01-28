const gcd = (a, b) => b === 0 ? a : gcd(b, a % b);
const lcm = (a, b) => a * (b / gcd(a, b));

function solution(n, m) {
    return [gcd(n, m), lcm(n, m)];
}
