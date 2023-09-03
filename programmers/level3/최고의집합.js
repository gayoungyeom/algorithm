function solution(n, s) {
    const ans = [];

    while(n !== 0){
        const mid = parseInt(s / n);
        
        if(mid === 0){
            ans.push(-1);
            break;
        }
        
        ans.push(mid);
        n--;
        s -= mid;
    }
    
    return ans;
}


