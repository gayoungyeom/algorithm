function solution(s) {
    const stack = [s[0]];
    
    for(let i = 1; i < s.length; i++){
        if(stack.length === 0) {
            stack.push(s[i]);
            continue;
        }
        
        const cur = stack.pop();
        if(s[i] !== cur){
            stack.push(cur);
            stack.push(s[i]);
        }
    }

    return stack.length === 0 ? 1 : 0;
}
