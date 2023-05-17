function diagonalDifference(arr) {
    const n = arr.length;
    let left = 0;
    let right = 0;
    
    for(let i = 0; i < n; i++){
        for(let j = 0; j < n; j++){
            if(i === j) left += arr[i][j];
            if(i + j === n - 1) right += arr[i][j];
        }
    }

    return Math.abs(left - right);
}
