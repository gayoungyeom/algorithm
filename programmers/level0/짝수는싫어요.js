function solution(n) {
    const arrN = Array.from({length: n}, (_, i) => i + 1)
    return arrN.filter(arr => arr % 2 !== 0);
}
