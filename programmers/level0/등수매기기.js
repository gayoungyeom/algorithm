function solution(score) {
    const total = score.map(s => s[0] + s[1]);
    const sorted = total.slice().sort((a, b) => b - a);
    return total.map(t => sorted.indexOf(t) + 1);
}`
