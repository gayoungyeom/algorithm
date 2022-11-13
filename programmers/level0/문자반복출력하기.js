function solution(my_string, n) {
    const repeat = [...my_string].map(s => s.repeat(n)).join('');
    return repeat;
}
