//1. for
function solution(arr1, arr2) {
    const m = [];
    for(let i = 0; i < arr1.length; i++){
        const r = [];
        for(let j = 0; j < arr1[i].length; j++)
            r.push(arr1[i][j] + arr2[i][j]);
        m.push(r);
    }
    return m;
}

//2. map
function solution(arr1, arr2) {
    return arr1.map((arr, i) => arr.map((v, j) => v + arr2[i][j]));
}

