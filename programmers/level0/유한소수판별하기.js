//1. 소수 활용 풀이
const gcd = (a, b) => b === 0 ? a : gcd(b, a % b);

const isPrime = (n) => {
    if(n < 2) return false;
    for(let i = 2; i*i <= n; i++){
        if(n % i === 0) return false;
    }
    return true;
}

function solution(a, b) {
    const g = gcd(a, b);
    const tmp = b / g;
    const factorization = [...Array(tmp + 1).keys()].slice(2).filter(num => isPrime(num) && tmp % num === 0);
    
    return factorization.some(num => num !== 2 && num !== 5) ? 2 : 1;
}


//2. a, b의 제한 덕분에 가능한 풀이
function solution(a, b) {
    return Number((a / b).toFixed(10)) === a / b ? 1 : 2;
}
