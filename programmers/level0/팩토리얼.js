//1. 나누기
function solution(n) {
    let tmp = n;    
    for(let i = 1; i <= 10; i++){
        tmp /= i;
        if(tmp < i + 1) return i;
    }
}

//2. 더 직관적인 방법인듯 (+나눗셈보다 곱셈이 안전)
function solution(n) {
    let fact = 1;
    let i = 1;
    while(fact <= n){
        fact *= i;
        i++;
    }
    return i-2;
}
