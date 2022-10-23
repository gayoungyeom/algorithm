const compareNumber = (a, b) => a - b;

function solution(numbers) {
    numbers.sort(compareNumber);
    return numbers.at(-1) * numbers.at(-2);
}
