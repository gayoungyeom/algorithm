//x 범위: max-min < x < max+min 
function solution(sides) {
    return 2 * Math.min(...sides) - 1;
}
