const GAME = ['3', '6', '9'];

function solution(order) {
    return [...String(order)].reduce((cnt, cur) => GAME.includes(cur) ? cnt += 1 : cnt, 0);
}
