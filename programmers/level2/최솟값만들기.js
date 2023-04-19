function solution(A,B){
    A.sort((a, b) => a - b);
    B.sort((a, b) => a - b);
    
    let sum = 0;
    const n = A.length;
    for(let i = 0; i < n; i++){
        sum += (A[i] * B[n - i - 1]);
    }
    return sum;
}
