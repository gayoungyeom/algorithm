function solution(order) {
    const stack = [];
    let cur = 0; //트럭에 실어야 하는 택배
    
    for(let i = 1; i <= order.length; i++) {
        if(order[cur] === i) cur++;
        else stack.push(i);
        
        while(stack.length !== 0 && stack[stack.length - 1] === order[cur]){
            stack.pop();
            cur++;
        }
    }
    
    return cur;
}
