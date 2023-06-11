function solution(numbers) {
    const n = numbers.length;
    const stack = [];
    const result = [...Array(n).fill(-1)];
    
    for(let i = 0; i < n; i++){
        while(stack.length !== 0 && numbers[stack[stack.length - 1]] < numbers[i]){
            result[stack.pop()] = numbers[i];
        }
        stack.push(i);
    }
    
    return result;
}
