function solution(age) {
    return [...age.toString()].map(a => String.fromCodePoint(Number(a) + 97)).join('');
}
