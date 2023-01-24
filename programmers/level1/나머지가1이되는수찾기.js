//1. 수행 시간은 이게 빠름
function solution(n) {
    for(let i = n - 2; i >= 1; i--){
        if((n - 1) % i === 0){
            return (n - 1) / i;
        }
    }
}

//2. 내장 메서드 활용
function solution(n) {
    return [...Array(n).keys()].filter(v => n % v === 1)[0];
}
