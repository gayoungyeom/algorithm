const gcd = (a, b) => b === 0 ? a : gcd(b, a % b);

function solution(numer1, denom1, numer2, denom2) {
    const n = numer1 * denom2 + numer2 * denom1;
    const d = denom1 * denom2;
    const g = gcd(n, d);
    return [n / g, d / g];
}
