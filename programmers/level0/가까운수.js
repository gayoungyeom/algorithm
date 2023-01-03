//1
function solution(array, n) {  
    array.sort();
    const diff = array.map(a => Math.abs(a - n));
    const minIdx = diff.indexOf(Math.min(...diff));
    return array[minIdx];
}

//2
function solution(array, n) {  
    array.sort((a, b) => a - b);
    return array.reduce((acc, cur) => Math.abs(acc - n) > Math.abs(cur - n) ? cur : acc, array[0]);
}
