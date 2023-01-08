function solution(numbers, k) {
    const len = numbers.length;
    return (2 * k - 1) % len; //(1 + (2 * (k - 1))) % len
}
