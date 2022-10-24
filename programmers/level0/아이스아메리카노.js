const ICE_AMERICANO = 5500;

function solution(money) {
    const count = ~~(money / ICE_AMERICANO);
    const change = money - (count * ICE_AMERICANO);
    return [count, change]
}
