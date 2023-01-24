//1. 직관
function solution(a, b) {
    const [min, max] = a < b ? [a, b] : [b, a];
    
    let sum = 0;
    for(let i = min; i <= max; i++){
        sum += i;
    }
    return sum;
}

//2. 등차가 1인 수열의 합
function solution(a, b) {
    return (a + b) * (Math.abs(a - b) + 1) / 2;
}
