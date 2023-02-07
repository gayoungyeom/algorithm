const MAX = 1000001;
const check = Array(MAX).fill(false);

const isPrime = () => {
    check[0] = check[1] = true;
    for(let i = 2; i * i <= MAX; i++){
        if(!check[i]){
            for(let j = i + i; j <= MAX; j+=i)
                check[j] = true;
        }
    }
}

function solution(n) {
    isPrime();
    return [...Array(n+1).keys()].slice(2).reduce((cnt, cur) => check[cur] ? cnt : cnt + 1, 0);

