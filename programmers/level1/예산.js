function solution(d, budget) {
    return d.sort((a, b) => a - b).reduce((acc, cur) => {
        if(budget < cur) return acc;
        budget -= cur;
        return acc + 1;
    }, 0)
}
