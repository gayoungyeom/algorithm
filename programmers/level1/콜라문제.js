function solution(a, b, n) {
    let sum = 0;
    while(n >= a){
        const coke = ~~(n / a) * b;
    
        sum += coke;
        n = coke + n % a;
    }
    return sum;
}
