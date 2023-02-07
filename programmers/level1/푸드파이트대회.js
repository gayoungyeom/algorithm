function solution(food) {
    const order = food.map((v, i) => String(i).repeat(~~v/2)).join('');
    return `${order}0${[...order].reverse().join('')}`;
}
