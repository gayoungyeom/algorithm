function solution(n) {
    let sum = 0;
    for(let i = 1; i*i <= n; i++){
        if(n % i === 0){
            sum += i;
            if(i * i === n) continue;
            sum += (n / i);
        }
    }
    return sum;
}
