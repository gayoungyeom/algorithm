function solution(arr1, arr2) {
    const n = arr1.length;
    const m = arr2[0].length;
    let result = Array.from(Array(n), () => Array(m).fill(0));

    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            for(let k = 0; k < arr1[0].length; k++){
                result[i][j] += (arr1[i][k] * arr2[k][j]);
            }
        }
    }
    
    return result;
}
