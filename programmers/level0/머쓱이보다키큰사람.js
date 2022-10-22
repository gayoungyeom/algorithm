function solution(array, height) {
    const taller = array.filter(arr => arr > height);
    return taller.length;
}
