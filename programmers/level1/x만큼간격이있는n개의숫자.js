//1. 반복문
function solution(x, n) {
    const number = [];
    let i = x;
    while(n--){
        number.push(i);
        i += x;
    }
    return number;
}

//2. 함수형 (실행 속도는 위보다 더 느린듯)
function solution(x, n) {
    return [...Array(n+1).keys()].slice(1).map(v => v * x);
}
