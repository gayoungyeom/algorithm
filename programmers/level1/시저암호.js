const UPPER_CASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const LOWER_CASE = "abcdefghijklmnopqrstuvwxyz";

function solution(s, n) {
    return [...s].map((c, i) => c === " " ? c :
        c.toUpperCase() === c ? UPPER_CASE[(UPPER_CASE.indexOf(c) + n) % 26] : LOWER_CASE[(LOWER_CASE.indexOf(c) + n) % 26]
    ).join('');
}
