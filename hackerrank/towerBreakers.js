//??? 모든 타워의 높이가 m으로 같다는 것이 포인트
function towerBreakers(n, m) {
    if(m === 1 || n % 2 === 0) return 2;
    return 1;
}
