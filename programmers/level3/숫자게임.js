function solution(A, B) {
    const n = A.length;
    A.sort((a, b) => a - b);
    B.sort((a, b) => a - b);
    
    let i = 0, j = 0;
    let result = 0;
    
    while(i < n && j < n){
        if(A[i] < B[j]){
            result++;
            i++;
        }
        j++;
    }
    
    return result;
}
