//1. for
function solution(s) {
    const n = s.length;
    const ans = [...Array(n).fill(-1)];
    
    for(let i = 1; i < n; i++){
        for(let j = i - 1; j >= 0; j--){
            if(s[i] === s[j]) {
                ans[i] = i - j;
                break;
            }
        }
    }
        
    return ans;
}

//2. lastIndexOf
function solution(s) {
    return [...s].map((c, i) => {
        const lastIdx = s.slice(0, i).lastIndexOf(c);
        return lastIdx === -1 ? lastIdx : i - lastIdx;
    });
}
