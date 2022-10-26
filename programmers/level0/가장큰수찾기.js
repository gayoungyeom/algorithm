function solution(array) {
    const maxValue = Math.max(...array)
    const maxIndex = array.indexOf(maxValue);
    return [maxValue, maxIndex];
}
