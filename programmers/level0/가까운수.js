function solution(array, n) {  
    array.sort();
    const diff = array.map(a => Math.abs(a - n));
    const minIdx = diff.indexOf(Math.min(...diff));
    return array[minIdx];
}
