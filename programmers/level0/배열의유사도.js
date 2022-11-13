//s1과 s2의 위치가 바뀌어도 상관 없음
function solution(s1, s2) {
    const counting = s1.filter(s => s2.includes(s));
    return counting.length;
}
