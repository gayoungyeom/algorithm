function solution(n) {
    const word = "수박".repeat(Math.ceil(n / 2));
    return n % 2 ? word.slice(0, -1) : word;
}
