function solution(array, n) {
    const newArr = array.filter(a => a === n);
    return newArr.length;
}
