const gcd = (a, b) => b === 0 ? a : gcd(b, a % b);
const lcm = (a, b) => a * (b / gcd(a, b));

function solution(arr) {
    while(arr.length > 1){
        arr.splice(0, 2, lcm(arr[0], arr[1]));
    }
    return arr[0];
}
