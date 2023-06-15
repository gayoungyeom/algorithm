function solution(n) {
    let ans = '';
    
    while(n > 0){
        const rmd = (n - 1) % 3;
        n = ~~((n - 1) / 3);
        
        if(rmd === 0) ans += '1';
        else if(rmd === 1) ans += '2';
        else ans += '4';
    }
    
    return [...ans].reverse().join('');
}
