function solution(numbers) {
    const sum = numbers.reduce((prev, cur) => prev + cur);
    const size = numbers.length;
    return sum / size;
}
