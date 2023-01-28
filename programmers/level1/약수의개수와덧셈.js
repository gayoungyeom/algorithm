//1. 반복문
function solution(left, right) {
    let sum = 0;
    for(let i = left; i <= right; i++){
        let cnt = 0;
        for(let j = 1; j*j <= i; j++){
            if(i % j !== 0) continue;
            
            if(j*j === i) cnt++;
            else cnt += 2;           
        }
        if(cnt % 2 === 0) sum += i;
        else sum -= i;
    }   
    return sum;
}

//2. reduce
const divCnt = (n) => [...Array(Math.ceil(Math.sqrt(n+1))).keys()].slice(1)
    .reduce((acc, cur) => {
        if(n % cur) return acc;
        if(cur * cur === n) return acc += 1;
        return acc += 2;
    }, 0);
            
function solution(left, right) {
    return [...Array(right+1).keys()].slice(left)
        .reduce((acc, cur) => divCnt(cur) % 2 ? acc -= cur : acc += cur, 0);
}

//3. 제곱근이 정수면, 약수의 개수가 홀수이다..!
function solution(left, right) {
    let sum = 0;
    for(let i = left; i <= right; i++){
        if(Number.isInteger(Math.sqrt(i))) sum -= i;
        else sum += i;
    }   
    return sum;
}
