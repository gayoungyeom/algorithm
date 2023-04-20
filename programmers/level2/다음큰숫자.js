function solution(n) {
    const binary = n.toString(2);
    const oneLen = [...binary].filter(v => v === '1').length;
    
    let result = 0;
    while(1){
        n++;
        const next = n.toString(2);
        const len = [...next].filter(v => v === '1').length;
        if(oneLen === len) {
            result = parseInt(next, 2);
            break;
        }
    }
    
    return result;
}
