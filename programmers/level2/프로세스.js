function solution(priorities, location) {
    const n = priorities.length;
    let cnt = 1;

    while(1){
        const max = Math.max(...priorities);
        const cur = priorities.shift();
        
        if(cur === max){
            if(location === 0) break;
            cnt++;
        } else{
            priorities.push(cur);
        }
        location = location === 0 ? priorities.length - 1 : location - 1;
    }
    
    return cnt;
}
