function solution(number, limit, power) {
    let p = 0;
    for(let i = 1; i <= number; i++){
        let cnt = 0;
        for(let j = 1; j * j <= i; j++){
            if(i % j === 0) cnt += 2;
            if(j * j === i) cnt -= 1;
        }
        p += (cnt > limit ? power : cnt);
    }
    return p;
}
