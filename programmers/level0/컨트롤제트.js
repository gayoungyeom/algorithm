function solution(s) {
    const stack = [];
    s.split(" ").forEach(cur => cur === "Z" ? stack.pop() : stack.push(cur));
    return stack.reduce((acc, cur) => acc + Number(cur), 0);
}
