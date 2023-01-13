function solution(n) {
    let num = 0;
    let passed = 0;
    
    while(passed !== n){
        num++;
        if(num % 3 !== 0 && !String(num).includes("3")) passed++;
    }
    
    return num;
}
