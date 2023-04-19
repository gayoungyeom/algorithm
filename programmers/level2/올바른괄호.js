//1. 기존 풀이 w/ stack
function solution(s){
    const stack = [];
    for(const cur of s){
        if(cur === '('){
            stack.push(cur);
        } else{
            if(stack.length === 0) return false;
            stack.pop();
        }
    }
    if(stack.length !== 0) return false;
    return true;
}

//2. 효율성
function solution(s){
    let cnt = 0;
    for(const cur of s){
        if(cur === '('){
            cnt++;
        } else{
            cnt--;
            if(cnt < 0) return false;
        }
    }
    return cnt === 0;
}
