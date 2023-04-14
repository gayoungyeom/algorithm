function solution(price, money, count) {
    const cost = price * ((count * (count + 1)) / 2);
    return money - cost < 0 ? cost - money : 0;
}
