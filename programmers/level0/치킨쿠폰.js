function solution(chicken) {
    const free = chicken - 10;
    return free < 0 ? 0 : ~~(free / 9) + 1;
}
