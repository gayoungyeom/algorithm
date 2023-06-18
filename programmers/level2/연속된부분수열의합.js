//누적합 스킬 -> i에서 j까지 누적합 = j까지 누적합 - (i-1)까지 누적합
function solution(sequence, k) {
    const n = sequence.length;
    const accSum = [0];
    for(let i = 0; i < n; i++) accSum.push(accSum[i] + sequence[i]);
    
    let minLen = n + 1;
    let start = 0, end = n - 1;
    let i = 1, j = 1;
    
    while(i <= j){
        const sum = accSum[j] - accSum[i - 1]; //i부터 j까지 합
        if(sum === k){
            if(j - i + 1 < minLen){
                minLen = j - i + 1;
                start = i;
                end = j;
            }
        } 
        
        if(sum < k) j++;
        else i++;
    }    
    
    return [start - 1, end - 1];
}
