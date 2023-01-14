const isPrime = (n) => {
    if(n < 2) return false;
    for(let i = 2; i*i <= n; i++){
        if(n % i === 0) return false;
    }
    return true;
}

function solution(n) {
    return [...Array(n+1).keys()].slice(2).filter(num => !isPrime(num)).length;
}
