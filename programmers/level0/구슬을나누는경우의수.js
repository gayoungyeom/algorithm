//큰 수로 인한 오류 발생 가능성이 있으므로 BigInt를 사용해야 함!
const fact = (n) => [...Array(n + 1).keys()].slice(1).reduce((acc, cur) => BigInt(acc) * BigInt(cur), BigInt(1));

function solution(balls, share) {
    return fact(balls) / (fact(balls-share) * fact(share));
}

