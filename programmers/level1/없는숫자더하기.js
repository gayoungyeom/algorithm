const SUM = 45;

function solution(numbers) {
    return SUM - numbers.reduce((a, b) => a + b);    
}
