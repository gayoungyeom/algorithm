// {x + (x+1) + ... + (x+(num-1))} = total
function solution(num, total) {
    const x = (total - ((num * num - num) / 2)) / num;
    return [...Array(num).keys()].map(i => x + i);
}
