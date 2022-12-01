function solution(my_string) {
    return [...my_string].reduce((sum, cur) => !isNaN(cur) ? sum += Number(cur) : sum, 0);
}
