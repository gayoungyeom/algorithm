//1. 반복문
function solution(s) {    
    let x = s[0];
    let cntX = 1, cntY = 0, ans = 0;

    for(let i = 1; i < s.length; i++){
        if(s[i] === x) cntX++;
        else cntY++;
        
        if(cntX === cntY) {
            x = s[++i];
            ans++;
            cntX = 1;
            cntY = 0;
        }
    }
    
    return x ? ans + 1 : ans;
}

//2. 재귀
function solution(s, count = 0) {
    if(!s) return count;

    let [x, ...rest] = s.split('');
    let cntX = 1, cntY = 0, i = 0;
    for(; i < rest.length; i++){
        if(rest[i] === x) cntX++;
        else cntY++;
        
        if(cntX === cntY) break;
    }

    return solution(rest.slice(i + 1).join(''), count + 1);
}
